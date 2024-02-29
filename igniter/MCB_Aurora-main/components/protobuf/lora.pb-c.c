/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: lora.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "lora.pb-c.h"
void   lo_ra_frame__init
                     (LoRaFrame         *message)
{
  static const LoRaFrame init_value = LO_RA_FRAME__INIT;
  *message = init_value;
}
size_t lo_ra_frame__get_packed_size
                     (const LoRaFrame *message)
{
  assert(message->base.descriptor == &lo_ra_frame__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t lo_ra_frame__pack
                     (const LoRaFrame *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &lo_ra_frame__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t lo_ra_frame__pack_to_buffer
                     (const LoRaFrame *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &lo_ra_frame__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
LoRaFrame *
       lo_ra_frame__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (LoRaFrame *)
     protobuf_c_message_unpack (&lo_ra_frame__descriptor,
                                allocator, len, data);
}
void   lo_ra_frame__free_unpacked
                     (LoRaFrame *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &lo_ra_frame__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   lo_ra_command__init
                     (LoRaCommand         *message)
{
  static const LoRaCommand init_value = LO_RA_COMMAND__INIT;
  *message = init_value;
}
size_t lo_ra_command__get_packed_size
                     (const LoRaCommand *message)
{
  assert(message->base.descriptor == &lo_ra_command__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t lo_ra_command__pack
                     (const LoRaCommand *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &lo_ra_command__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t lo_ra_command__pack_to_buffer
                     (const LoRaCommand *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &lo_ra_command__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
LoRaCommand *
       lo_ra_command__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (LoRaCommand *)
     protobuf_c_message_unpack (&lo_ra_command__descriptor,
                                allocator, len, data);
}
void   lo_ra_command__free_unpacked
                     (LoRaCommand *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &lo_ra_command__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   lo_ra_settings__init
                     (LoRaSettings         *message)
{
  static const LoRaSettings init_value = LO_RA_SETTINGS__INIT;
  *message = init_value;
}
size_t lo_ra_settings__get_packed_size
                     (const LoRaSettings *message)
{
  assert(message->base.descriptor == &lo_ra_settings__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t lo_ra_settings__pack
                     (const LoRaSettings *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &lo_ra_settings__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t lo_ra_settings__pack_to_buffer
                     (const LoRaSettings *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &lo_ra_settings__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
LoRaSettings *
       lo_ra_settings__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (LoRaSettings *)
     protobuf_c_message_unpack (&lo_ra_settings__descriptor,
                                allocator, len, data);
}
void   lo_ra_settings__free_unpacked
                     (LoRaSettings *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &lo_ra_settings__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor lo_ra_frame__field_descriptors[36] =
{
  {
    "obc_state",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, obc_state),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "dc_time",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, dc_time),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "flight_time",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, flight_time),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "mcb_battery",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, mcb_battery),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "gps_lat",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, gps_lat),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "gps_long",
    6,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, gps_long),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "gps_sat",
    7,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, gps_sat),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "mcb_altitude",
    8,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, mcb_altitude),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "mcb_velocity",
    9,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, mcb_velocity),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "mcb_temperature",
    10,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, mcb_temperature),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "euler_fi",
    11,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, euler_fi),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "euler_psi",
    12,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, euler_psi),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "euler_theta",
    13,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, euler_theta),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "recov_pressure_1",
    14,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, recov_pressure_1),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "recov_pressure_2",
    15,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, recov_pressure_2),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "recov_byte_data",
    16,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, recov_byte_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pitot_battery",
    17,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, pitot_battery),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pitot_altitude",
    18,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, pitot_altitude),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pitot_velocity",
    19,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, pitot_velocity),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pitot_temperature",
    20,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, pitot_temperature),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "mval_battery",
    21,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, mval_battery),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "mval_byte_data",
    22,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, mval_byte_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vent_battery",
    23,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, vent_battery),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tank_pressure",
    24,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, tank_pressure),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vent_byte_data",
    25,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, vent_byte_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tanwa_battery",
    26,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, tanwa_battery),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tanwa_byte_data",
    27,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, tanwa_byte_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tanwa_state",
    28,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, tanwa_state),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "rocket_weight",
    29,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, rocket_weight),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tank_weight",
    30,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, tank_weight),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "temperature1",
    31,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, temperature1),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "temperature2",
    32,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, temperature2),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pressure",
    33,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, pressure),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload_battery",
    34,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, payload_battery),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "esp_now_byte_data",
    35,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, esp_now_byte_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "errors",
    36,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED32,
    0,   /* quantifier_offset */
    offsetof(LoRaFrame, errors),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned lo_ra_frame__field_indices_by_name[] = {
  1,   /* field[1] = dc_time */
  35,   /* field[35] = errors */
  34,   /* field[34] = esp_now_byte_data */
  10,   /* field[10] = euler_fi */
  11,   /* field[11] = euler_psi */
  12,   /* field[12] = euler_theta */
  2,   /* field[2] = flight_time */
  4,   /* field[4] = gps_lat */
  5,   /* field[5] = gps_long */
  6,   /* field[6] = gps_sat */
  7,   /* field[7] = mcb_altitude */
  3,   /* field[3] = mcb_battery */
  9,   /* field[9] = mcb_temperature */
  8,   /* field[8] = mcb_velocity */
  20,   /* field[20] = mval_battery */
  21,   /* field[21] = mval_byte_data */
  0,   /* field[0] = obc_state */
  33,   /* field[33] = payload_battery */
  17,   /* field[17] = pitot_altitude */
  16,   /* field[16] = pitot_battery */
  19,   /* field[19] = pitot_temperature */
  18,   /* field[18] = pitot_velocity */
  32,   /* field[32] = pressure */
  15,   /* field[15] = recov_byte_data */
  13,   /* field[13] = recov_pressure_1 */
  14,   /* field[14] = recov_pressure_2 */
  28,   /* field[28] = rocket_weight */
  23,   /* field[23] = tank_pressure */
  29,   /* field[29] = tank_weight */
  25,   /* field[25] = tanwa_battery */
  26,   /* field[26] = tanwa_byte_data */
  27,   /* field[27] = tanwa_state */
  30,   /* field[30] = temperature1 */
  31,   /* field[31] = temperature2 */
  22,   /* field[22] = vent_battery */
  24,   /* field[24] = vent_byte_data */
};
static const ProtobufCIntRange lo_ra_frame__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 36 }
};
const ProtobufCMessageDescriptor lo_ra_frame__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "LoRaFrame",
  "LoRaFrame",
  "LoRaFrame",
  "",
  sizeof(LoRaFrame),
  36,
  lo_ra_frame__field_descriptors,
  lo_ra_frame__field_indices_by_name,
  1,  lo_ra_frame__number_ranges,
  (ProtobufCMessageInit) lo_ra_frame__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor lo_ra_command__field_descriptors[4] =
{
  {
    "lora_dev_id",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaCommand, lora_dev_id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sys_dev_id",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaCommand, sys_dev_id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "command",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaCommand, command),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaCommand, payload),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned lo_ra_command__field_indices_by_name[] = {
  2,   /* field[2] = command */
  0,   /* field[0] = lora_dev_id */
  3,   /* field[3] = payload */
  1,   /* field[1] = sys_dev_id */
};
static const ProtobufCIntRange lo_ra_command__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor lo_ra_command__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "LoRaCommand",
  "LoRaCommand",
  "LoRaCommand",
  "",
  sizeof(LoRaCommand),
  4,
  lo_ra_command__field_descriptors,
  lo_ra_command__field_indices_by_name,
  1,  lo_ra_command__number_ranges,
  (ProtobufCMessageInit) lo_ra_command__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor lo_ra_settings__field_descriptors[6] =
{
  {
    "lora_freq_khz",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaSettings, lora_freq_khz),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "lora_transmit_ms",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaSettings, lora_transmit_ms),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "countdown_time",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaSettings, countdown_time),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ingition_time",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(LoRaSettings, ingition_time),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "flash_enable",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaSettings, flash_enable),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "buzzer_enable",
    6,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LoRaSettings, buzzer_enable),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned lo_ra_settings__field_indices_by_name[] = {
  5,   /* field[5] = buzzer_enable */
  2,   /* field[2] = countdown_time */
  4,   /* field[4] = flash_enable */
  3,   /* field[3] = ingition_time */
  0,   /* field[0] = lora_freq_khz */
  1,   /* field[1] = lora_transmit_ms */
};
static const ProtobufCIntRange lo_ra_settings__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor lo_ra_settings__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "LoRaSettings",
  "LoRaSettings",
  "LoRaSettings",
  "",
  sizeof(LoRaSettings),
  6,
  lo_ra_settings__field_descriptors,
  lo_ra_settings__field_indices_by_name,
  1,  lo_ra_settings__number_ranges,
  (ProtobufCMessageInit) lo_ra_settings__init,
  NULL,NULL,NULL    /* reserved[123] */
};