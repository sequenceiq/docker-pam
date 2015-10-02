#!/bin/sh

errorExit() {
	echo "*** $*" 1>&2
	exit 1
}

yum clean metadata || errorExit "Error cleaning yum metadata."
yum update -y || errorExit "Error yum-updating."
rpm -qa >/tmp/old-rpms.lst
yum install -y tar bzip2 yum-utils rpm-build || errorExit "Error installing dependencies."

yum-builddep -y pam || errorExit "Error in yum-builddep."
yumdownloader --source pam || errorExit "Error downloading sources."

export RPM_BUILD_NCPUS=`nproc`
rpmbuild --rebuild  --define 'WITH_AUDIT 0' --define 'dist +noaudit' pam*.src.rpm || errorExit "Error rebuilding."

TO_REMOVE=""
for i in `rpm -qa`; do
	if ! grep -q "^${i}$" /tmp/old-rpms.lst; then
		TO_REMOVE="$TO_REMOVE $i"
	fi
done
echo "Removing `echo $TO_REMOVE | wc -w` unneeded packages."
yum remove -y $TO_REMOVE || errorExit "Error removing unneeded software."

if [ `rpm -qa | wc -l` -ne `cat /tmp/old-rpms.lst | wc -l` ]; then
	errorExit "Error, we've got inconsistent packages, `rpm -qa | wc -l` instead of `cat /tmp/old-rpms.lst | wc -l`."
fi

rpm -Uvh --oldpackage ~/rpmbuild/RPMS/*/pam*+noaudit*.rpm || errorExit "Error installing newly built PAM rpms."

yum clean all
rm -f /*.rpm
rm -rf ~/rpmbuild
rm -f /tmp/old-rpms.lst
