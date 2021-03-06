/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*	@(#)sigsuspend.c	1.0	9/22/95	(c) 1995 NeXT	*/

#include <signal.h>
#include <unistd.h>

#ifdef VARIANT_CANCELABLE
int __sigsuspend (const sigset_t);
#else /* !VARIANT_CANCELABLE */
int __sigsuspend_nocancel(const sigset_t);
#endif /* VARIANT_CANCELABLE */

int
sigsuspend (const sigset_t *sigmask_p)
{
    sigset_t	mask;

    if (sigmask_p)
        mask = *sigmask_p;
    else
        sigemptyset(&mask);
#ifdef VARIANT_CANCELABLE
    return __sigsuspend(mask);
#else /* !VARIANT_CANCELABLE */
    return __sigsuspend_nocancel(mask);
#endif /* VARIANT_CANCELABLE */
}

