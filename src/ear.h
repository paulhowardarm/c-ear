// Copyright 2023 Contributors to the Veraison project.
// SPDX-License-Identifier: Apache-2.0

#ifndef EAR_H
#define EAR_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef EAR_ERR_SZ
#define EAR_ERR_SZ 128
#endif // !EAR_ERR_SZ

// forward declaration
typedef struct ear_s ear_t;

/**
 * @brief Verify an EAT Attestation Result in JWT format.
 *
 * Verify an EAT Attestation Result in JWT format using the supplied public key.
 * On success, the decoded EAR claims-set is returned.
 *
 * @param[in]   ear_jwt NUL-terminated C string with the JWT carrying the EAR
 *                      claims-set
 * @param[in]   pkey    The public key for verification.  The format is
 *                      described in Section 13 of RFC7468
 * @param[in]   pkey_sz Size in bytes of @p pkey
 * @param[out]  pear    Pointer to a ear_t object which, on success, will be
 *                      populated with the EAR claims-set.  This needs to be
 *                      provided by the caller
 * @param[out]  err_msg pointer to a pre-allocated buffer (of at least
 *                      @c EAR_ERR_SZ bytes) which, on failure, will be filled
 *                      in by the callee with a human readable error message.
 *                      This can set to NULL if no extra error reporting is
 *                      required
 *
 * @retval  0   on success
 * @retval  -1  on failure
 */
int ear_jwt_verify(const char *ear_jwt, const uint8_t *pkey, size_t pkey_sz,
                   ear_t **pear, char err_msg[EAR_ERR_SZ]);

/**
 * @brief Return the value of the "ear.status" claim
 *
 * On success, a NUL-terminated C string with the the value of the "ear.status"
 * claim is returned.  On failure a NULL value is returned and, if supplied, the
 * @p err_msg is filled with the failure reason.
 *
 * @param[in]   ear     an ear_t object returned from a successful invocation of
 *                      ear_jwt_verify
 * @param[out]  err_msg pointer to a pre-allocated buffer (of at least @c
 *                      EAR_ERR_SZ bytes) which, on failure, will be filled in
 *                      by the callee with a human readable error message.  This
 *                      can set to NULL if no extra error reporting is required
 *
 * @retval  the status string on success
 * @retval  NULL on failure
 */
const char *ear_get_status(ear_t *ear, char err_msg[EAR_ERR_SZ]);

/**
 * @brief Free an ear_t object allocated by ear_jwt_verify
 *
 * @param ear the ear_t object to free
 */
void ear_free(ear_t *ear);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !EAR_H