#!/bin/bash

./configure --prefix=/usr \
            --sysconfdir=/etc \
            --libdir=/usr/lib \
            --enable-securedir=/lib/security \
            --docdir=/usr/share/doc/Linux-PAM-1.1.8 &&
make && make install &&
chmod -v 4755 /sbin/unix_chkpwd &&
for file in pam pam_misc pamc
do
  mv -v /usr/lib/lib${file}.so.* /lib &&
  ln -sfv ../../lib/$(readlink /usr/lib/lib${file}.so) /usr/lib/lib${file}.so
done

