#Docker PAM workaround

### Pull the image

```
docker pull sequenceiq/pam
```


Alternatively you can build the image from the Dockerfile from our [GitHub repository](https://github.com/sequenceiq/docker-pam)

### Build the image

```
docker build --rm -t pam .
```

### Test the image

####Test with CentOS container as guest OS with patched PAM 

```
docker run -i -t --net=host pam /bin/bash -c "useradd testuser; su testuser"
```
**Output shall look like this:**
vagrant@vagrant-ubuntu-trusty-64:~/docker-pam$ sudo docker run -i -t --net=host pam_test /bin/bash -c "useradd testuser; su testuser"

[testuser@vagrant-ubuntu-trusty-64 /]


####Test with CentOS container as guest OS without patched PAM 

```
docker run -i -t --net=host tianon/centos:6.5 /bin/bash -c "useradd testuser; su testuser"
```
**Output shall look like this:**
vagrant@vagrant-ubuntu-trusty-64:~/docker-pam$ sudo docker run -i -t --net=host tianon/centos:6.5 /bin/bash -c "useradd testuser; su testuser"

su: incorrect password
