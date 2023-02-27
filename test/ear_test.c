
// Copyright 2023 Contributors to the Veraison project.
// SPDX-License-Identifier: Apache-2.0

#include "ear.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

uint8_t pkey[] = {
    0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x50,
    0x55, 0x42, 0x4c, 0x49, 0x43, 0x20, 0x4b, 0x45, 0x59, 0x2d, 0x2d, 0x2d,
    0x2d, 0x2d, 0x0a, 0x4d, 0x46, 0x6b, 0x77, 0x45, 0x77, 0x59, 0x48, 0x4b,
    0x6f, 0x5a, 0x49, 0x7a, 0x6a, 0x30, 0x43, 0x41, 0x51, 0x59, 0x49, 0x4b,
    0x6f, 0x5a, 0x49, 0x7a, 0x6a, 0x30, 0x44, 0x41, 0x51, 0x63, 0x44, 0x51,
    0x67, 0x41, 0x45, 0x75, 0x73, 0x57, 0x78, 0x48, 0x4b, 0x32, 0x50, 0x6d,
    0x66, 0x6e, 0x48, 0x4b, 0x77, 0x58, 0x50, 0x53, 0x35, 0x34, 0x6d, 0x30,
    0x6b, 0x54, 0x63, 0x47, 0x4a, 0x39, 0x30, 0x0a, 0x55, 0x69, 0x67, 0x6c,
    0x57, 0x69, 0x47, 0x61, 0x68, 0x74, 0x61, 0x67, 0x6e, 0x76, 0x38, 0x67,
    0x45, 0x34, 0x76, 0x34, 0x4c, 0x63, 0x47, 0x32, 0x31, 0x57, 0x4b, 0x2b,
    0x44, 0x36, 0x56, 0x4b, 0x74, 0x34, 0x42, 0x4b, 0x4f, 0x6d, 0x53, 0x32,
    0x31, 0x79, 0x7a, 0x50, 0x37, 0x57, 0x74, 0x76, 0x74, 0x75, 0x30, 0x6f,
    0x75, 0x2f, 0x77, 0x52, 0x66, 0x67, 0x3d, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d,
    0x2d, 0x2d, 0x45, 0x4e, 0x44, 0x20, 0x50, 0x55, 0x42, 0x4c, 0x49, 0x43,
    0x20, 0x4b, 0x45, 0x59, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a};

size_t pkey_sz = sizeof pkey;

void test_jwt_verify_valid_ear(void) {
  ear_t *ear;
  const char *valid_ear =
      "eyJhbGciOiJFUzI1NiIsInR5cCI6IkpXVCJ9."
      "eyJlYXIucmF3LWV2aWRlbmNlIjoiTnpRM01qWTVOek0yTlRZek56UUsiLCJlYXIudmVyaWZp"
      "ZXItaWQiOnsiYnVpbGQiOiJ2dHMgMC4wLjEiLCJkZXZlbG9wZXIiOiJodHRwczovL3ZlcmFp"
      "c29uLXByb2plY3Qub3JnIn0sImVhdF9wcm9maWxlIjoidGFnOmdpdGh1Yi5jb20sMjAyMzp2"
      "ZXJhaXNvbi9lYXIiLCJpYXQiOjEuNjY2NTI5MTg0ZSswOSwianRpIjoiNTViOGIzZmFkOGRk"
      "MWQ4ZWFjNGU0OGYxMTdmZTUwOGIxMWY4NDRkOWYwMTg5YmZlZDliODc1MTVhNjc1NDI2NCIs"
      "Im5iZiI6MTY3NzI0Nzg3OSwic3VibW9kcyI6eyJQQVJTRUNfVFBNIjp7ImVhci5hcHByYWlz"
      "YWwtcG9saWN5LWlkIjoiaHR0cHM6Ly92ZXJhaXNvbi5leGFtcGxlL3BvbGljeS8xLzYwYTAw"
      "NjhkIiwiZWFyLnN0YXR1cyI6ImFmZmlybWluZyIsImVhci50cnVzdHdvcnRoaW5lc3MtdmVj"
      "dG9yIjp7ImV4ZWN1dGFibGVzIjoyLCJoYXJkd2FyZSI6MiwiaW5zdGFuY2UtaWRlbnRpdHki"
      "OjJ9LCJlYXIudmVyYWlzb24ua2V5LWF0dGVzdGF0aW9uIjp7ImFrcHViIjoiTUZrd0V3WUhL"
      "b1pJemowQ0FRWUlLb1pJemowREFRY0RRZ0FFY2pTcDhfTVdNM2d5OFR1Z1dPMVRwUVNqX3ZJ"
      "a3NMcEMtZzhsNVMzbHBHYjdQV1dHb0NBakVQOF9BNTlWWndMWGd3b1p6TjBXeHVCUGpwYVdp"
      "V3NmQ1EifX19fQ."
      "3Ym-f1LEgamxePUM7h6Y2RJDGh9eeL0xKor0n1wE9jdAnLNwm3rTKFV2S2LbqVFoDtK9QGal"
      "T2t5RnUdfwZNmg";

  int ret = ear_jwt_verify(valid_ear, pkey, pkey_sz, "ES256", &ear, NULL);
  TEST_ASSERT(ret == 0);

  ear_tier_t tier;

  ret = ear_get_status(ear, "PARSEC_TPM", &tier, NULL);
  TEST_ASSERT(ret == 0);
  TEST_ASSERT_EQUAL_INT(EAR_TIER_AFFIRMING, tier);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_jwt_verify_valid_ear);
  return UNITY_END();
}
