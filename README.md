#Docker PAM workaround

# Build the image

```
docker build --rm -t pam-test .
```

# Test the image

Test with CentOS container with patched PAM 

```
docker run -i -t --net=host pam-test /bin/bash -c "useradd testuser; su testuser"

#Output shall look like this:
vagrant@vagrant-ubuntu-trusty-64:~/docker-pam$ sudo docker run -i -t --net=host pam_test /bin/bash -c "useradd testuser; su testuser"
[testuser@vagrant-ubuntu-trusty-64 /]

```

Test with CentOS container without patched PAM 

```
docker run -i -t --net=host tianon/centos:6.5 /bin/bash -c "useradd testuser; su testuser"

#Output shall look like this:
vagrant@vagrant-ubuntu-trusty-64:~/docker-pam$ sudo docker run -i -t --net=host tianon/centos:6.5 /bin/bash -c "useradd testuser; su testuser"
su: incorrect password
```
