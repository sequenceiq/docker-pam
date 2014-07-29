/* Copyright © 2007, 2008 Red Hat, Inc. All rights reserved.
   Red Hat author: Miloslav Trmač <mitr@redhat.com>

   Redistribution and use in source and binary forms of Linux-PAM, with
   or without modification, are permitted provided that the following
   conditions are met:

   1. Redistributions of source code must retain any existing copyright
      notice, and this entire permission notice in its entirety,
      including the disclaimer of warranties.

   2. Redistributions in binary form must reproduce all prior and current
      copyright notices, this list of conditions, and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.

   3. The name of any author may not be used to endorse or promote
      products derived from this software without their specific prior
      written permission.

   ALTERNATIVELY, this product may be distributed under the terms of the
   GNU General Public License, in which case the provisions of the GNU
   GPL are required INSTEAD OF the above restrictions.  (This clause is
   necessary due to a potential conflict between the GNU GPL and the
   restrictions contained in a BSD-style copyright.)

   THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
   IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
   OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
   TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
   USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
   DAMAGE. */

#include <errno.h>
#include <fnmatch.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <sys/socket.h>
#include <unistd.h>

#include <libaudit.h>
#include <linux/netlink.h>

#define PAM_SM_SESSION

#include <security/pam_ext.h>
#include <security/pam_modules.h>
#include <security/pam_modutil.h>

#define DATANAME "pam_tty_audit_last_state"

/* Open an audit netlink socket */
static int
nl_open (void)
{
  return 0;
}

static int
nl_send (int fd, unsigned type, unsigned flags, const void *data, size_t size)
{
  return 0;
}

static int
nl_recv (int fd, unsigned type, void *buf, size_t size)
{
  return 0;
}

static int
nl_recv_ack (int fd)
{
  return 0;
}

static void
cleanup_old_status (pam_handle_t *pamh, void *data, int error_status)
{
}

int
pam_sm_open_session (pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return PAM_SUCCESS;
}

int
pam_sm_close_session (pam_handle_t *pamh, int flags, int argc,
		      const char **argv)
{
  return PAM_SUCCESS;
}

/* static module data */
#ifdef PAM_STATIC
struct pam_module _pam_tty_audit_modstruct = {
  "pam_tty_audit",
  NULL,
  NULL,
  NULL,
  pam_sm_open_session,
  pam_sm_close_session,
  NULL
};
#endif
