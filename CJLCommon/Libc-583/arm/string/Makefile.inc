# $Version$
#
# ARM-optimised string functions.
#
.PATH: ${.CURDIR}/arm/string

MDSRCS +=	\
	bcopy.s \
	bzero.s \
	ffs.s \
	strcmp.s \
	strlen.s

.if defined(FEATURE_ARM_ARCH_6)
MDSRCS += memset_pattern.s
.endif

SUPPRESSSRCS += memcpy.c memmove.c memset.c strlen.c
