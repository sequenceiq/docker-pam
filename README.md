#Docker PAM workaround

If you start your docker container with host networking enabled then due to a kernel bug commands like `su` does not work.
One solution for this issue is to patch the host kernel with the following: [AUDIT: Allow login in non-init namespaces](https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/patch/?id=543bc6a1a987672b79d6ebe8e2ab10471d8f1047
)


Another option is to patch the libpam on the guest OS running inside the docker container. For this purpose the `sequenceiq/pam` images are created for the most popular operating systems.

### Pull the image

```
docker pull sequenceiq/pam:centos-6.5
docker pull sequenceiq/pam:ubuntu-14.04
```

Alternatively you can build the image from the Dockerfile from our [GitHub repository](https://github.com/sequenceiq/docker-pam)

### Build the image

Building the Centos 6.5 with PAM audit disabled.
```
cd centos-6.5
docker build --rm -t pam_centos .
```
Building the ubuntu 14.04 with PAM audit disabled.
```
cd ubuntu-14.04
docker build --rm -t pam_ubuntu .
```
### Test the image

```
$ sudo docker run -i -t --net=host sequenceiq/pam:centos-6.5 /bin/bash -c "useradd testuser; su testuser"
$
```

As reference you can try the original CentOS 6.5 container as guest OS without patched PAM

```
$ sudo docker run -i -t --net=host tianon/centos:6.5 /bin/bash -c "useradd testuser; su testuser"
$ su: incorrect password
```
