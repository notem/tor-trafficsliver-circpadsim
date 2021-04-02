/* circpad_negotiation.c -- generated by Trunnel v1.5.3.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#include <stdlib.h>
#include "trunnel-impl.h"

#include "circpad_negotiation.h"

#define TRUNNEL_SET_ERROR_CODE(obj) \
  do {                              \
    (obj)->trunnel_error_code_ = 1; \
  } while (0)

#if defined(__COVERITY__) || defined(__clang_analyzer__)
/* If we're running a static analysis tool, we don't want it to complain
 * that some of our remaining-bytes checks are dead-code. */
int circpadnegotiation_deadcode_dummy__ = 0;
#define OR_DEADCODE_DUMMY || circpadnegotiation_deadcode_dummy__
#else
#define OR_DEADCODE_DUMMY
#endif

#define CHECK_REMAINING(nbytes, label)                           \
  do {                                                           \
    if (remaining < (nbytes) OR_DEADCODE_DUMMY) {                \
      goto label;                                                \
    }                                                            \
  } while (0)

circpad_negotiate_t *
circpad_negotiate_new(void)
{
  circpad_negotiate_t *val = trunnel_calloc(1, sizeof(circpad_negotiate_t));
  if (NULL == val)
    return NULL;
  val->command = CIRCPAD_COMMAND_LOG;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
circpad_negotiate_clear(circpad_negotiate_t *obj)
{
  (void) obj;
}

void
circpad_negotiate_free(circpad_negotiate_t *obj)
{
  if (obj == NULL)
    return;
  circpad_negotiate_clear(obj);
  trunnel_memwipe(obj, sizeof(circpad_negotiate_t));
  trunnel_free_(obj);
}

uint8_t
circpad_negotiate_get_version(const circpad_negotiate_t *inp)
{
  return inp->version;
}
int
circpad_negotiate_set_version(circpad_negotiate_t *inp, uint8_t val)
{
  if (! ((val == 0))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->version = val;
  return 0;
}
uint8_t
circpad_negotiate_get_command(const circpad_negotiate_t *inp)
{
  return inp->command;
}
int
circpad_negotiate_set_command(circpad_negotiate_t *inp, uint8_t val)
{
  if (! ((val == CIRCPAD_COMMAND_LOG || val == CIRCPAD_COMMAND_START || val == CIRCPAD_COMMAND_STOP))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->command = val;
  return 0;
}
uint8_t
circpad_negotiate_get_machine_type(const circpad_negotiate_t *inp)
{
  return inp->machine_type;
}
int
circpad_negotiate_set_machine_type(circpad_negotiate_t *inp, uint8_t val)
{
  inp->machine_type = val;
  return 0;
}
uint8_t
circpad_negotiate_get_echo_request(const circpad_negotiate_t *inp)
{
  return inp->echo_request;
}
int
circpad_negotiate_set_echo_request(circpad_negotiate_t *inp, uint8_t val)
{
  if (! ((val == 0 || val == 1))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->echo_request = val;
  return 0;
}
uint32_t
circpad_negotiate_get_machine_ctr(const circpad_negotiate_t *inp)
{
  return inp->machine_ctr;
}
int
circpad_negotiate_set_machine_ctr(circpad_negotiate_t *inp, uint32_t val)
{
  inp->machine_ctr = val;
  return 0;
}
uint32_t
circpad_negotiate_get_client_circid(const circpad_negotiate_t *inp)
{
  return inp->client_circid;
}
int
circpad_negotiate_set_client_circid(circpad_negotiate_t *inp, uint32_t val)
{
  inp->client_circid = val;
  return 0;
}
const char *
circpad_negotiate_check(const circpad_negotiate_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  if (! (obj->version == 0))
    return "Integer out of bounds";
  if (! (obj->command == CIRCPAD_COMMAND_LOG || obj->command == CIRCPAD_COMMAND_START || obj->command == CIRCPAD_COMMAND_STOP))
    return "Integer out of bounds";
  if (! (obj->echo_request == 0 || obj->echo_request == 1))
    return "Integer out of bounds";
  return NULL;
}

ssize_t
circpad_negotiate_encoded_len(const circpad_negotiate_t *obj)
{
  ssize_t result = 0;

  if (NULL != circpad_negotiate_check(obj))
     return -1;


  /* Length of u8 version IN [0] */
  result += 1;

  /* Length of u8 command IN [CIRCPAD_COMMAND_LOG, CIRCPAD_COMMAND_START, CIRCPAD_COMMAND_STOP] */
  result += 1;

  /* Length of u8 machine_type */
  result += 1;

  /* Length of u8 echo_request IN [0, 1] */
  result += 1;

  /* Length of u32 machine_ctr */
  result += 4;

  /* Length of u32 client_circid */
  result += 4;
  return result;
}
int
circpad_negotiate_clear_errors(circpad_negotiate_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
circpad_negotiate_encode(uint8_t *output, const size_t avail, const circpad_negotiate_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = circpad_negotiate_encoded_len(obj);
#endif

  if (NULL != (msg = circpad_negotiate_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 version IN [0] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->version));
  written += 1; ptr += 1;

  /* Encode u8 command IN [CIRCPAD_COMMAND_LOG, CIRCPAD_COMMAND_START, CIRCPAD_COMMAND_STOP] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->command));
  written += 1; ptr += 1;

  /* Encode u8 machine_type */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->machine_type));
  written += 1; ptr += 1;

  /* Encode u8 echo_request IN [0, 1] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->echo_request));
  written += 1; ptr += 1;

  /* Encode u32 machine_ctr */
  trunnel_assert(written <= avail);
  if (avail - written < 4)
    goto truncated;
  trunnel_set_uint32(ptr, trunnel_htonl(obj->machine_ctr));
  written += 4; ptr += 4;

  /* Encode u32 client_circid */
  trunnel_assert(written <= avail);
  if (avail - written < 4)
    goto truncated;
  trunnel_set_uint32(ptr, trunnel_htonl(obj->client_circid));
  written += 4; ptr += 4;


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As circpad_negotiate_parse(), but do not allocate the output
 * object.
 */
static ssize_t
circpad_negotiate_parse_into(circpad_negotiate_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 version IN [0] */
  CHECK_REMAINING(1, truncated);
  obj->version = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->version == 0))
    goto fail;

  /* Parse u8 command IN [CIRCPAD_COMMAND_LOG, CIRCPAD_COMMAND_START, CIRCPAD_COMMAND_STOP] */
  CHECK_REMAINING(1, truncated);
  obj->command = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->command == CIRCPAD_COMMAND_LOG || obj->command == CIRCPAD_COMMAND_START || obj->command == CIRCPAD_COMMAND_STOP))
    goto fail;

  /* Parse u8 machine_type */
  CHECK_REMAINING(1, truncated);
  obj->machine_type = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse u8 echo_request IN [0, 1] */
  CHECK_REMAINING(1, truncated);
  obj->echo_request = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->echo_request == 0 || obj->echo_request == 1))
    goto fail;

  /* Parse u32 machine_ctr */
  CHECK_REMAINING(4, truncated);
  obj->machine_ctr = trunnel_ntohl(trunnel_get_uint32(ptr));
  remaining -= 4; ptr += 4;

  /* Parse u32 client_circid */
  CHECK_REMAINING(4, truncated);
  obj->client_circid = trunnel_ntohl(trunnel_get_uint32(ptr));
  remaining -= 4; ptr += 4;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 fail:
  result = -1;
  return result;
}

ssize_t
circpad_negotiate_parse(circpad_negotiate_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = circpad_negotiate_new();
  if (NULL == *output)
    return -1;
  result = circpad_negotiate_parse_into(*output, input, len_in);
  if (result < 0) {
    circpad_negotiate_free(*output);
    *output = NULL;
  }
  return result;
}
circpad_negotiated_t *
circpad_negotiated_new(void)
{
  circpad_negotiated_t *val = trunnel_calloc(1, sizeof(circpad_negotiated_t));
  if (NULL == val)
    return NULL;
  val->command = CIRCPAD_COMMAND_START;
  val->response = CIRCPAD_RESPONSE_ERR;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
circpad_negotiated_clear(circpad_negotiated_t *obj)
{
  (void) obj;
}

void
circpad_negotiated_free(circpad_negotiated_t *obj)
{
  if (obj == NULL)
    return;
  circpad_negotiated_clear(obj);
  trunnel_memwipe(obj, sizeof(circpad_negotiated_t));
  trunnel_free_(obj);
}

uint8_t
circpad_negotiated_get_version(const circpad_negotiated_t *inp)
{
  return inp->version;
}
int
circpad_negotiated_set_version(circpad_negotiated_t *inp, uint8_t val)
{
  if (! ((val == 0))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->version = val;
  return 0;
}
uint8_t
circpad_negotiated_get_command(const circpad_negotiated_t *inp)
{
  return inp->command;
}
int
circpad_negotiated_set_command(circpad_negotiated_t *inp, uint8_t val)
{
  if (! ((val == CIRCPAD_COMMAND_START || val == CIRCPAD_COMMAND_STOP))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->command = val;
  return 0;
}
uint8_t
circpad_negotiated_get_response(const circpad_negotiated_t *inp)
{
  return inp->response;
}
int
circpad_negotiated_set_response(circpad_negotiated_t *inp, uint8_t val)
{
  if (! ((val == CIRCPAD_RESPONSE_ERR || val == CIRCPAD_RESPONSE_OK))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->response = val;
  return 0;
}
uint8_t
circpad_negotiated_get_machine_type(const circpad_negotiated_t *inp)
{
  return inp->machine_type;
}
int
circpad_negotiated_set_machine_type(circpad_negotiated_t *inp, uint8_t val)
{
  inp->machine_type = val;
  return 0;
}
uint32_t
circpad_negotiated_get_machine_ctr(const circpad_negotiated_t *inp)
{
  return inp->machine_ctr;
}
int
circpad_negotiated_set_machine_ctr(circpad_negotiated_t *inp, uint32_t val)
{
  inp->machine_ctr = val;
  return 0;
}
const char *
circpad_negotiated_check(const circpad_negotiated_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  if (! (obj->version == 0))
    return "Integer out of bounds";
  if (! (obj->command == CIRCPAD_COMMAND_START || obj->command == CIRCPAD_COMMAND_STOP))
    return "Integer out of bounds";
  if (! (obj->response == CIRCPAD_RESPONSE_ERR || obj->response == CIRCPAD_RESPONSE_OK))
    return "Integer out of bounds";
  return NULL;
}

ssize_t
circpad_negotiated_encoded_len(const circpad_negotiated_t *obj)
{
  ssize_t result = 0;

  if (NULL != circpad_negotiated_check(obj))
     return -1;


  /* Length of u8 version IN [0] */
  result += 1;

  /* Length of u8 command IN [CIRCPAD_COMMAND_START, CIRCPAD_COMMAND_STOP] */
  result += 1;

  /* Length of u8 response IN [CIRCPAD_RESPONSE_ERR, CIRCPAD_RESPONSE_OK] */
  result += 1;

  /* Length of u8 machine_type */
  result += 1;

  /* Length of u32 machine_ctr */
  result += 4;
  return result;
}
int
circpad_negotiated_clear_errors(circpad_negotiated_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
circpad_negotiated_encode(uint8_t *output, const size_t avail, const circpad_negotiated_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = circpad_negotiated_encoded_len(obj);
#endif

  if (NULL != (msg = circpad_negotiated_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 version IN [0] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->version));
  written += 1; ptr += 1;

  /* Encode u8 command IN [CIRCPAD_COMMAND_START, CIRCPAD_COMMAND_STOP] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->command));
  written += 1; ptr += 1;

  /* Encode u8 response IN [CIRCPAD_RESPONSE_ERR, CIRCPAD_RESPONSE_OK] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->response));
  written += 1; ptr += 1;

  /* Encode u8 machine_type */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->machine_type));
  written += 1; ptr += 1;

  /* Encode u32 machine_ctr */
  trunnel_assert(written <= avail);
  if (avail - written < 4)
    goto truncated;
  trunnel_set_uint32(ptr, trunnel_htonl(obj->machine_ctr));
  written += 4; ptr += 4;


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As circpad_negotiated_parse(), but do not allocate the output
 * object.
 */
static ssize_t
circpad_negotiated_parse_into(circpad_negotiated_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 version IN [0] */
  CHECK_REMAINING(1, truncated);
  obj->version = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->version == 0))
    goto fail;

  /* Parse u8 command IN [CIRCPAD_COMMAND_START, CIRCPAD_COMMAND_STOP] */
  CHECK_REMAINING(1, truncated);
  obj->command = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->command == CIRCPAD_COMMAND_START || obj->command == CIRCPAD_COMMAND_STOP))
    goto fail;

  /* Parse u8 response IN [CIRCPAD_RESPONSE_ERR, CIRCPAD_RESPONSE_OK] */
  CHECK_REMAINING(1, truncated);
  obj->response = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->response == CIRCPAD_RESPONSE_ERR || obj->response == CIRCPAD_RESPONSE_OK))
    goto fail;

  /* Parse u8 machine_type */
  CHECK_REMAINING(1, truncated);
  obj->machine_type = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse u32 machine_ctr */
  CHECK_REMAINING(4, truncated);
  obj->machine_ctr = trunnel_ntohl(trunnel_get_uint32(ptr));
  remaining -= 4; ptr += 4;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 fail:
  result = -1;
  return result;
}

ssize_t
circpad_negotiated_parse(circpad_negotiated_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = circpad_negotiated_new();
  if (NULL == *output)
    return -1;
  result = circpad_negotiated_parse_into(*output, input, len_in);
  if (result < 0) {
    circpad_negotiated_free(*output);
    *output = NULL;
  }
  return result;
}
