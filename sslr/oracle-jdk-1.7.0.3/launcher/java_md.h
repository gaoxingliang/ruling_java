/*
 * Copyright (c) 1998, 2005, Oracle and/or its affiliates. All rights reserved.
 * ORACLE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#ifndef JAVA_MD_H
#define JAVA_MD_H

#include <limits.h>
#include <unistd.h>
#include <sys/param.h>
#include "manifest_info.h"
#include "jli_util.h"

#define PATH_SEPARATOR          ':'
#define FILESEP                 "/"
#define FILE_SEPARATOR          '/'
#define IS_FILE_SEPARATOR(c) ((c) == '/')
#ifndef MAXNAMELEN
#define MAXNAMELEN              PATH_MAX
#endif

#ifdef HAVE_GETHRTIME
/*
 * Support for doing cheap, accurate interval timing.
 */
#include <sys/time.h>
#define CounterGet()              (gethrtime()/1000)
#define Counter2Micros(counts)    (counts)
#else
#define CounterGet()              (0)
#define Counter2Micros(counts)    (1)
#endif /* HAVE_GETHRTIME */

/*
 * Function prototypes.
 */
char *LocateJRE(manifest_info *info);
void ExecJRE(char *jre, char **argv);
int UnsetEnv(char *name);

#endif
