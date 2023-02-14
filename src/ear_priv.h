// Copyright 2023 Contributors to the Veraison project.
// SPDX-License-Identifier: Apache-2.0

#ifndef EAR_PRIV_H
#define EAR_PRIV_H

#include <jwt.h>
#include <stddef.h>

/* The ear object is currently just a wrapper around the jwt_t to hide any
 * implementation details from the caller */
typedef struct ear_s {
  jwt_t *jwt;
} ear_t;

size_t u_strlcpy(char *dst, const char *src, size_t sz);

#endif // !EAR_PRIV_H