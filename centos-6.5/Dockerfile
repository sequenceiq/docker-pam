FROM tianon/centos:6.5
MAINTAINER SequenceIQ

ADD Centos-Source.repo /etc/yum.repos.d/Centos-Source.repo
ADD build.sh /tmp/build.sh

RUN sh /tmp/build.sh && rm -f /tmp/build.sh
