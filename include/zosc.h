/*  =========================================================================
    zosc - work with Open Sound Control messages

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of CZMQ, the high-level C binding for 0MQ:
    http://czmq.zeromq.org.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef ZOSC_H_INCLUDED
#define ZOSC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/zosc.api" to make changes.
//  @interface
//  This is a draft class, and may change without notice. It is disabled in
//  stable builds by default. If you use this in applications, please ask
//  for it to be pushed to stable state. Use --enable-drafts to enable.
#ifdef CZMQ_BUILD_DRAFT_API
//  *** Draft method, for development use, may change without warning ***
//  Create a new empty OSC message with the specified address string.
CZMQ_EXPORT zosc_t *
    zosc_new (const char *address);

//  *** Draft method, for development use, may change without warning ***
//  Create a new OSC message from the specified zframe. Takes ownership of
//  the zframe.
CZMQ_EXPORT zosc_t *
    zosc_fromframe (zframe_t *frame);

//  *** Draft method, for development use, may change without warning ***
//  Create a new zosc message from memory. Take ownership of the memory
//  and calling free on the data after construction.
CZMQ_EXPORT zosc_t *
    zosc_frommem (char *data, size_t size);

//  *** Draft method, for development use, may change without warning ***
//  Create a new zosc message from the given format and arguments.
//  The format type tags are as follows:
//    i - 32bit integer
//    h - 64bit integer
//    f - 32bit floating point number (IEEE)
//    d - 64bit (double) floating point number
//    s - string (NULL terminated)
//    t = timetag: an OSC timetag in NTP format (uint64_t)
//    S - symbol
//    c - char
//    m - 4 byte midi packet (8 digits hexadecimal)
//    T - TRUE (no value required)
//    F - FALSE (no value required)
//    N - NIL (no value required)
//    I - Impulse (for triggers) or INFINITUM (no value required)
//    b - binary blob
CZMQ_EXPORT zosc_t *
    zosc_create (const char *address, const char *format, ...);

//  *** Draft method, for development use, may change without warning ***
//  Destroy an OSC message
CZMQ_EXPORT void
    zosc_destroy (zosc_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Return chunk data size
CZMQ_EXPORT size_t
    zosc_size (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return OSC chunk data. Caller does not own the data!
CZMQ_EXPORT byte *
    zosc_data (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return the OSC address string
CZMQ_EXPORT const char *
    zosc_address (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return the OSC format of the message.
//    i - 32bit integer
//    h - 64bit integer
//    f - 32bit floating point number (IEEE)
//    d - 64bit (double) floating point number
//    s - string (NULL terminated)
//    t = timetag: an OSC timetag in NTP format (uint64_t)
//    S - symbol
//    c - char
//    m - 4 byte midi packet (8 digits hexadecimal)
//    T - TRUE (no value required)
//    F - FALSE (no value required)
//    N - NIL (no value required)
//    I - Impulse (for triggers) or INFINITUM (no value required)
//    b - binary blob
CZMQ_EXPORT const char *
    zosc_format (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Retrieve the values provided by the given format. Note that zosc_retr
//  creates the objects and the caller must destroy them when finished.
//  The supplied pointers do not need to be initialized. Returns 0 if
//  successful, or -1 if it failed to retrieve a value in which case the
//  pointers are not modified. If an argument pointer is NULL is skips the
//  value. See the format method for a detailed list op type tags for the
//  format string.
CZMQ_EXPORT int
    zosc_retr (zosc_t *self, const char *format, ...);

//  *** Draft method, for development use, may change without warning ***
//  Create copy of the message, as new chunk object. Returns a fresh zosc_t
//  object, or null if there was not enough heap memory. If chunk is null,
//  returns null.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zosc_t *
    zosc_dup (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Transform zosc into a zframe that can be sent in a message.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zframe_t *
    zosc_pack (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Transform zosc into a zframe that can be sent in a message.
//  Take ownership of the chunk.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zframe_t *
    zosc_packx (zosc_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Transform a zframe into a zosc.
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT zosc_t *
    zosc_unpack (zframe_t *frame);

//  *** Draft method, for development use, may change without warning ***
//  Dump OSC message to stdout, for debugging and tracing.
CZMQ_EXPORT void
    zosc_print (zosc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Probe the supplied object, and report if it looks like a zosc_t.
CZMQ_EXPORT bool
    zosc_is (void *self);

//  *** Draft method, for development use, may change without warning ***
//  Return a pointer to the item at the head of the OSC data.
//  Sets the given char argument to the type tag of the data.
//  If the message is empty, returns NULL and the sets the
//  given char to NULL.
CZMQ_EXPORT const void *
    zosc_first (zosc_t *self, char *type);

//  *** Draft method, for development use, may change without warning ***
//  Return the next item of the OSC message. If the list is empty, returns
//  NULL. To move to the start of the OSC message call zosc_first ().
CZMQ_EXPORT const void *
    zosc_next (zosc_t *self, char *type);

//  *** Draft method, for development use, may change without warning ***
//  Return a pointer to the item at the tail of the OSC message.
//  Sets the given char argument to the type tag of the data. If
//  the message is empty, returns NULL.
CZMQ_EXPORT const void *
    zosc_last (zosc_t *self, char *type);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided 32 bit integer from value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_int32 (zosc_t *self, int *val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided 64 bit integer from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_int64 (zosc_t *self, int64_t *val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided float from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_float (zosc_t *self, float *val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided double from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_double (zosc_t *self, double *val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided string from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success. Caller owns the string!
CZMQ_EXPORT int
    zosc_pop_string (zosc_t *self, char **val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided char from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_char (zosc_t *self, char *val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided boolean from the type tag in the message. Booleans are not represented
//  in the data in the message, only in the type tag. If the type tag at the current
//  position does not correspond it will fail and return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_bool (zosc_t *self, bool *val);

//  *** Draft method, for development use, may change without warning ***
//  Set the provided 4 bytes (unsigned 32bit int) from the value at the current
//  cursor position in the message. If the type tag at the current position does
//  not correspond it will fail and return -1. Returns 0 on success.
CZMQ_EXPORT int
    zosc_pop_midi (zosc_t *self, uint32_t *val);

//  *** Draft method, for development use, may change without warning ***
//  Self test of this class.
CZMQ_EXPORT void
    zosc_test (bool verbose);

#endif // CZMQ_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif