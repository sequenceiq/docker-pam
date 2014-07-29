#!/bin/bash

./configure --prefix=/usr \
            --sysconfdir=/etc \
            --libdir=/usr/lib64 \
            --enable-securedir=/lib64/security \
            --docdir=/usr/share/doc/Linux-PAM-1.1.8 &&
make && make install &&
chmod -v 4755 /sbin/unix_chkpwd &&
for file in pam pam_misc pamc
do
  mv -v /usr/lib64/lib${file}.so.* /lib64 &&
  ln -sfv ../../lib64/$(readlink /usr/lib64/lib${file}.so) /usr/lib64/lib${file}.so
done

