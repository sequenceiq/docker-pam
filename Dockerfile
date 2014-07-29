FROM tianon/centos:6.5
MAINTAINER SequenceIQ

RUN yum install -y unzip curl tar bzip2 wget pam-devel bison flex gperf libtool texinfo gcc gcc-c++ gmp-devel expat expat-devel python python-devel kernel-devel patch

RUN cd /root && wget http://linux-pam.org/library/Linux-PAM-1.1.8.tar.bz2
RUN mkdir /root/pam && cd /root/pam && tar -xf ../Linux-PAM-1.1.8.tar.bz2 --strip-components=1

#Patch the audit
ADD pam_tty_audit.c /root/pam/modules/pam_tty_audit/pam_tty_audit.c

ADD pam-setup.sh /root/pam/pam-setup.sh

RUN cd /root/pam && ./pam-setup.sh
