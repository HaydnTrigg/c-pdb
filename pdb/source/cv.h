#pragma once
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "msf.h"
#include "tpi.h"

#include "memory_stream.h"
#include "macros_decl.h"

/* ---------- CV signatures */

#define DBI_CV_SIGNATURE_ENUM \
ENUM_DECL(cv_signature_type) \
    ENUM_VALUE(CV_SIGNATURE_C6, 0) \
    ENUM_VALUE(CV_SIGNATURE_C7, 1) \
    ENUM_VALUE(CV_SIGNATURE_C11, 2) \
    ENUM_VALUE(CV_SIGNATURE_C13, 4) \
    ENUM_VALUE(CV_SIGNATURE_RESERVED, 5) \
ENUM_END(cv_signature_type)

DBI_CV_SIGNATURE_ENUM

void cv_signature_type_print(enum cv_signature_type signature, FILE *stream);

/* ---------- CV CPU types */

#define CV_CPU_TYPE_ENUM \
ENUM_DECL(cv_cpu_type) \
    ENUM_VALUE(CV_CPU_TYPE_INTEL8080, 0x0) \
    ENUM_VALUE(CV_CPU_TYPE_INTEL8086, 0x1) \
    ENUM_VALUE(CV_CPU_TYPE_INTEL80286, 0x2) \
    ENUM_VALUE(CV_CPU_TYPE_INTEL80386, 0x3) \
    ENUM_VALUE(CV_CPU_TYPE_INTEL80486, 0x4) \
    ENUM_VALUE(CV_CPU_TYPE_PENTIUM, 0x5) \
    ENUM_VALUE(CV_CPU_TYPE_PENTIUM_PRO, 0x6) \
    ENUM_VALUE(CV_CPU_TYPE_PENTIUM3, 0x7) \
    ENUM_VALUE(CV_CPU_TYPE_MIPS, 0x10) \
    ENUM_VALUE(CV_CPU_TYPE_MIPS16, 0x11) \
    ENUM_VALUE(CV_CPU_TYPE_MIPS32, 0x12) \
    ENUM_VALUE(CV_CPU_TYPE_MIPS64, 0x13) \
    ENUM_VALUE(CV_CPU_TYPE_MIPSI, 0x14) \
    ENUM_VALUE(CV_CPU_TYPE_MIPSII, 0x15) \
    ENUM_VALUE(CV_CPU_TYPE_MIPSIII, 0x16) \
    ENUM_VALUE(CV_CPU_TYPE_MIPSIV, 0x17) \
    ENUM_VALUE(CV_CPU_TYPE_MIPSV, 0x18) \
    ENUM_VALUE(CV_CPU_TYPE_M68000, 0x20) \
    ENUM_VALUE(CV_CPU_TYPE_M68010, 0x21) \
    ENUM_VALUE(CV_CPU_TYPE_M68020, 0x22) \
    ENUM_VALUE(CV_CPU_TYPE_M68030, 0x23) \
    ENUM_VALUE(CV_CPU_TYPE_M68040, 0x24) \
    ENUM_VALUE(CV_CPU_TYPE_ALPHA, 0x30) \
    ENUM_VALUE(CV_CPU_TYPE_ALPHA21164, 0x31) \
    ENUM_VALUE(CV_CPU_TYPE_ALPHA21164_A, 0x32) \
    ENUM_VALUE(CV_CPU_TYPE_ALPHA21264, 0x33) \
    ENUM_VALUE(CV_CPU_TYPE_ALPHA21364, 0x34) \
    ENUM_VALUE(CV_CPU_TYPE_PPC601, 0x40) \
    ENUM_VALUE(CV_CPU_TYPE_PPC603, 0x41) \
    ENUM_VALUE(CV_CPU_TYPE_PPC604, 0x42) \
    ENUM_VALUE(CV_CPU_TYPE_PPC620, 0x43) \
    ENUM_VALUE(CV_CPU_TYPE_PPCFP, 0x44) \
    ENUM_VALUE(CV_CPU_TYPE_PPCBE, 0x45) \
    ENUM_VALUE(CV_CPU_TYPE_SH3, 0x50) \
    ENUM_VALUE(CV_CPU_TYPE_SH3_E, 0x51) \
    ENUM_VALUE(CV_CPU_TYPE_SH3_DSP, 0x52) \
    ENUM_VALUE(CV_CPU_TYPE_SH4, 0x53) \
    ENUM_VALUE(CV_CPU_TYPE_SH_MEDIA, 0x54) \
    ENUM_VALUE(CV_CPU_TYPE_ARM3, 0x60) \
    ENUM_VALUE(CV_CPU_TYPE_ARM4, 0x61) \
    ENUM_VALUE(CV_CPU_TYPE_ARM4_T, 0x62) \
    ENUM_VALUE(CV_CPU_TYPE_ARM5, 0x63) \
    ENUM_VALUE(CV_CPU_TYPE_ARM5_T, 0x64) \
    ENUM_VALUE(CV_CPU_TYPE_ARM6, 0x65) \
    ENUM_VALUE(CV_CPU_TYPE_ARM_XMAC, 0x66) \
    ENUM_VALUE(CV_CPU_TYPE_ARM_WMMX, 0x67) \
    ENUM_VALUE(CV_CPU_TYPE_ARM7, 0x68) \
    ENUM_VALUE(CV_CPU_TYPE_ARM64, 0x69) \
    ENUM_VALUE(CV_CPU_TYPE_OMNI, 0x70) \
    ENUM_VALUE(CV_CPU_TYPE_IA64, 0x80) \
    ENUM_VALUE(CV_CPU_TYPE_IA64_2, 0x81) \
    ENUM_VALUE(CV_CPU_TYPE_CEE, 0x90) \
    ENUM_VALUE(CV_CPU_TYPE_AM33, 0xa0) \
    ENUM_VALUE(CV_CPU_TYPE_M32_R, 0xb0) \
    ENUM_VALUE(CV_CPU_TYPE_TRI_CORE, 0xc0) \
    ENUM_VALUE(CV_CPU_TYPE_X64, 0xd0) \
    ENUM_VALUE(CV_CPU_TYPE_EBC, 0xe0) \
    ENUM_VALUE(CV_CPU_TYPE_THUMB, 0xf0) \
    ENUM_VALUE(CV_CPU_TYPE_ARMNT, 0xf4) \
    ENUM_VALUE(CV_CPU_TYPE_D3_D11_SHADER, 0x100) \
ENUM_END(cv_cpu_type)

CV_CPU_TYPE_ENUM

void cv_cpu_type_print(enum cv_cpu_type type, FILE *stream);

/* ---------- CV symbol types */

#define CV_SYMBOL_TYPE_ENUM                                    \
ENUM_DECL(cv_symbol_type)                                      \
    ENUM_VALUE(S_COMPILE, 0x0001)                              \
    ENUM_VALUE(S_REGISTER_16t, 0x0002)                         \
    ENUM_VALUE(S_CONSTANT_16t, 0x0003)                         \
    ENUM_VALUE(S_UDT_16t, 0x0004)                              \
    ENUM_VALUE(S_SSEARCH, 0x0005)                              \
    ENUM_VALUE(S_END, 0x0006)                                  \
    ENUM_VALUE(S_SKIP, 0x0007)                                 \
    ENUM_VALUE(S_CVRESERVE, 0x0008)                            \
    ENUM_VALUE(S_OBJNAME_ST, 0x0009)                           \
    ENUM_VALUE(S_ENDARG, 0x000a)                               \
    ENUM_VALUE(S_COBOLUDT_16t, 0x000b)                         \
    ENUM_VALUE(S_MANYREG_16t, 0x000c)                          \
    ENUM_VALUE(S_RETURN, 0x000d)                               \
    ENUM_VALUE(S_ENTRYTHIS, 0x000e)                            \
    ENUM_VALUE(S_BPREL16, 0x0100)                              \
    ENUM_VALUE(S_LDATA16, 0x0101)                              \
    ENUM_VALUE(S_GDATA16, 0x0102)                              \
    ENUM_VALUE(S_PUB16, 0x0103)                                \
    ENUM_VALUE(S_LPROC16, 0x0104)                              \
    ENUM_VALUE(S_GPROC16, 0x0105)                              \
    ENUM_VALUE(S_THUNK16, 0x0106)                              \
    ENUM_VALUE(S_BLOCK16, 0x0107)                              \
    ENUM_VALUE(S_WITH16, 0x0108)                               \
    ENUM_VALUE(S_LABEL16, 0x0109)                              \
    ENUM_VALUE(S_CEXMODEL16, 0x010a)                           \
    ENUM_VALUE(S_VFTABLE16, 0x010b)                            \
    ENUM_VALUE(S_REGREL16, 0x010c)                             \
    ENUM_VALUE(S_BPREL32_16t, 0x0200)                          \
    ENUM_VALUE(S_LDATA32_16t, 0x0201)                          \
    ENUM_VALUE(S_GDATA32_16t, 0x0202)                          \
    ENUM_VALUE(S_PUB32_16t, 0x0203)                            \
    ENUM_VALUE(S_LPROC32_16t, 0x0204)                          \
    ENUM_VALUE(S_GPROC32_16t, 0x0205)                          \
    ENUM_VALUE(S_THUNK32_ST, 0x0206)                           \
    ENUM_VALUE(S_BLOCK32_ST, 0x0207)                           \
    ENUM_VALUE(S_WITH32_ST, 0x0208)                            \
    ENUM_VALUE(S_LABEL32_ST, 0x0209)                           \
    ENUM_VALUE(S_CEXMODEL32, 0x020a)                           \
    ENUM_VALUE(S_VFTABLE32_16t, 0x020b)                        \
    ENUM_VALUE(S_REGREL32_16t, 0x020c)                         \
    ENUM_VALUE(S_LTHREAD32_16t, 0x020d)                        \
    ENUM_VALUE(S_GTHREAD32_16t, 0x020e)                        \
    ENUM_VALUE(S_SLINK32, 0x020f)                              \
    ENUM_VALUE(S_LPROCMIPS_16t, 0x0300)                        \
    ENUM_VALUE(S_GPROCMIPS_16t, 0x0301)                        \
    ENUM_VALUE(S_PROCREF_ST, 0x0400)                           \
    ENUM_VALUE(S_DATAREF_ST, 0x0401)                           \
    ENUM_VALUE(S_ALIGN, 0x0402)                                \
    ENUM_VALUE(S_LPROCREF_ST, 0x0403)                          \
    ENUM_VALUE(S_OEM, 0x0404)                                  \
    ENUM_VALUE(S_TI16_MAX, 0x1000)                             \
    ENUM_VALUE(S_REGISTER_ST, 0x1001)                          \
    ENUM_VALUE(S_CONSTANT_ST, 0x1002)                          \
    ENUM_VALUE(S_UDT_ST, 0x1003)                               \
    ENUM_VALUE(S_COBOLUDT_ST, 0x1004)                          \
    ENUM_VALUE(S_MANYREG_ST, 0x1005)                           \
    ENUM_VALUE(S_BPREL32_ST, 0x1006)                           \
    ENUM_VALUE(S_LDATA32_ST, 0x1007)                           \
    ENUM_VALUE(S_GDATA32_ST, 0x1008)                           \
    ENUM_VALUE(S_PUB32_ST, 0x1009)                             \
    ENUM_VALUE(S_LPROC32_ST, 0x100a)                           \
    ENUM_VALUE(S_GPROC32_ST, 0x100b)                           \
    ENUM_VALUE(S_VFTABLE32, 0x100c)                            \
    ENUM_VALUE(S_REGREL32_ST, 0x100d)                          \
    ENUM_VALUE(S_LTHREAD32_ST, 0x100e)                         \
    ENUM_VALUE(S_GTHREAD32_ST, 0x100f)                         \
    ENUM_VALUE(S_LPROCMIPS_ST, 0x1010)                         \
    ENUM_VALUE(S_GPROCMIPS_ST, 0x1011)                         \
    ENUM_VALUE(S_FRAMEPROC, 0x1012)                            \
    ENUM_VALUE(S_COMPILE2_ST, 0x1013)                          \
    ENUM_VALUE(S_MANYREG2_ST, 0x1014)                          \
    ENUM_VALUE(S_LPROCIA64_ST, 0x1015)                         \
    ENUM_VALUE(S_GPROCIA64_ST, 0x1016)                         \
    ENUM_VALUE(S_LOCALSLOT_ST, 0x1017)                         \
    ENUM_VALUE(S_PARAMSLOT_ST, 0x1018)                         \
    ENUM_VALUE(S_ANNOTATION, 0x1019)                           \
    ENUM_VALUE(S_GMANPROC_ST, 0x101a)                          \
    ENUM_VALUE(S_LMANPROC_ST, 0x101b)                          \
    ENUM_VALUE(S_RESERVED1, 0x101c)                            \
    ENUM_VALUE(S_RESERVED2, 0x101d)                            \
    ENUM_VALUE(S_RESERVED3, 0x101e)                            \
    ENUM_VALUE(S_RESERVED4, 0x101f)                            \
    ENUM_VALUE(S_LMANDATA_ST, 0x1020)                          \
    ENUM_VALUE(S_GMANDATA_ST, 0x1021)                          \
    ENUM_VALUE(S_MANFRAMEREL_ST, 0x1022)                       \
    ENUM_VALUE(S_MANREGISTER_ST, 0x1023)                       \
    ENUM_VALUE(S_MANSLOT_ST, 0x1024)                           \
    ENUM_VALUE(S_MANMANYREG_ST, 0x1025)                        \
    ENUM_VALUE(S_MANREGREL_ST, 0x1026)                         \
    ENUM_VALUE(S_MANMANYREG2_ST, 0x1027)                       \
    ENUM_VALUE(S_MANTYPREF, 0x1028)                            \
    ENUM_VALUE(S_UNAMESPACE_ST, 0x1029)                        \
    ENUM_VALUE(S_ST_MAX, 0x1100)                               \
    ENUM_VALUE(S_OBJNAME, 0x1101)                              \
    ENUM_VALUE(S_THUNK32, 0x1102)                              \
    ENUM_VALUE(S_BLOCK32, 0x1103)                              \
    ENUM_VALUE(S_WITH32, 0x1104)                               \
    ENUM_VALUE(S_LABEL32, 0x1105)                              \
    ENUM_VALUE(S_REGISTER, 0x1106)                             \
    ENUM_VALUE(S_CONSTANT, 0x1107)                             \
    ENUM_VALUE(S_UDT, 0x1108)                                  \
    ENUM_VALUE(S_COBOLUDT, 0x1109)                             \
    ENUM_VALUE(S_MANYREG, 0x110a)                              \
    ENUM_VALUE(S_BPREL32, 0x110b)                              \
    ENUM_VALUE(S_LDATA32, 0x110c)                              \
    ENUM_VALUE(S_GDATA32, 0x110d)                              \
    ENUM_VALUE(S_PUB32, 0x110e)                                \
    ENUM_VALUE(S_LPROC32, 0x110f)                              \
    ENUM_VALUE(S_GPROC32, 0x1110)                              \
    ENUM_VALUE(S_REGREL32, 0x1111)                             \
    ENUM_VALUE(S_LTHREAD32, 0x1112)                            \
    ENUM_VALUE(S_GTHREAD32, 0x1113)                            \
    ENUM_VALUE(S_LPROCMIPS, 0x1114)                            \
    ENUM_VALUE(S_GPROCMIPS, 0x1115)                            \
    ENUM_VALUE(S_COMPILE2, 0x1116)                             \
    ENUM_VALUE(S_MANYREG2, 0x1117)                             \
    ENUM_VALUE(S_LPROCIA64, 0x1118)                            \
    ENUM_VALUE(S_GPROCIA64, 0x1119)                            \
    ENUM_VALUE(S_LOCALSLOT, 0x111a)                            \
    ENUM_VALUE(S_SLOT, S_LOCALSLOT)                            \
    ENUM_VALUE(S_PARAMSLOT, 0x111b)                            \
    ENUM_VALUE(S_LMANDATA, 0x111c)                             \
    ENUM_VALUE(S_GMANDATA, 0x111d)                             \
    ENUM_VALUE(S_MANFRAMEREL, 0x111e)                          \
    ENUM_VALUE(S_MANREGISTER, 0x111f)                          \
    ENUM_VALUE(S_MANSLOT, 0x1120)                              \
    ENUM_VALUE(S_MANMANYREG, 0x1121)                           \
    ENUM_VALUE(S_MANREGREL, 0x1122)                            \
    ENUM_VALUE(S_MANMANYREG2, 0x1123)                          \
    ENUM_VALUE(S_UNAMESPACE, 0x1124)                           \
    ENUM_VALUE(S_PROCREF, 0x1125)                              \
    ENUM_VALUE(S_DATAREF, 0x1126)                              \
    ENUM_VALUE(S_LPROCREF, 0x1127)                             \
    ENUM_VALUE(S_ANNOTATIONREF, 0x1128)                        \
    ENUM_VALUE(S_TOKENREF, 0x1129)                             \
    ENUM_VALUE(S_GMANPROC, 0x112a)                             \
    ENUM_VALUE(S_LMANPROC, 0x112b)                             \
    ENUM_VALUE(S_TRAMPOLINE, 0x112c)                           \
    ENUM_VALUE(S_MANCONSTANT, 0x112d)                          \
    ENUM_VALUE(S_ATTR_FRAMEREL, 0x112e)                        \
    ENUM_VALUE(S_ATTR_REGISTER, 0x112f)                        \
    ENUM_VALUE(S_ATTR_REGREL, 0x1130)                          \
    ENUM_VALUE(S_ATTR_MANYREG, 0x1131)                         \
    ENUM_VALUE(S_SEPCODE, 0x1132)                              \
    ENUM_VALUE(S_LOCAL_2005, 0x1133)                           \
    ENUM_VALUE(S_DEFRANGE_2005, 0x1134)                        \
    ENUM_VALUE(S_DEFRANGE2_2005, 0x1135)                       \
    ENUM_VALUE(S_SECTION, 0x1136)                              \
    ENUM_VALUE(S_COFFGROUP, 0x1137)                            \
    ENUM_VALUE(S_EXPORT, 0x1138)                               \
    ENUM_VALUE(S_CALLSITEINFO, 0x1139)                         \
    ENUM_VALUE(S_FRAMECOOKIE, 0x113a)                          \
    ENUM_VALUE(S_DISCARDED, 0x113b)                            \
    ENUM_VALUE(S_COMPILE3, 0x113c)                             \
    ENUM_VALUE(S_ENVBLOCK, 0x113d)                             \
    ENUM_VALUE(S_LOCAL, 0x113e)                                \
    ENUM_VALUE(S_DEFRANGE, 0x113f)                             \
    ENUM_VALUE(S_DEFRANGE_SUBFIELD, 0x1140)                    \
    ENUM_VALUE(S_DEFRANGE_REGISTER, 0x1141)                    \
    ENUM_VALUE(S_DEFRANGE_FRAMEPOINTER_REL, 0x1142)            \
    ENUM_VALUE(S_DEFRANGE_SUBFIELD_REGISTER, 0x1143)           \
    ENUM_VALUE(S_DEFRANGE_FRAMEPOINTER_REL_FULL_SCOPE, 0x1144) \
    ENUM_VALUE(S_DEFRANGE_REGISTER_REL, 0x1145)                \
    ENUM_VALUE(S_LPROC32_ID, 0x1146)                           \
    ENUM_VALUE(S_GPROC32_ID, 0x1147)                           \
    ENUM_VALUE(S_LPROCMIPS_ID, 0x1148)                         \
    ENUM_VALUE(S_GPROCMIPS_ID, 0x1149)                         \
    ENUM_VALUE(S_LPROCIA64_ID, 0x114a)                         \
    ENUM_VALUE(S_GPROCIA64_ID, 0x114b)                         \
    ENUM_VALUE(S_BUILDINFO, 0x114c)                            \
    ENUM_VALUE(S_INLINESITE, 0x114d)                           \
    ENUM_VALUE(S_INLINESITE_END, 0x114e)                       \
    ENUM_VALUE(S_PROC_ID_END, 0x114f)                          \
    ENUM_VALUE(S_DEFRANGE_HLSL, 0x1150)                        \
    ENUM_VALUE(S_GDATA_HLSL, 0x1151)                           \
    ENUM_VALUE(S_LDATA_HLSL, 0x1152)                           \
    ENUM_VALUE(S_FILESTATIC, 0x1153)                           \
    ENUM_VALUE(S_LOCAL_DPC_GROUPSHARED, 0x1154)                \
    ENUM_VALUE(S_LPROC32_DPC, 0x1155)                          \
    ENUM_VALUE(S_LPROC32_DPC_ID, 0x1156)                       \
    ENUM_VALUE(S_DEFRANGE_DPC_PTR_TAG, 0x1157)                 \
    ENUM_VALUE(S_DPC_SYM_TAG_MAP, 0x1158)                      \
    ENUM_VALUE(S_ARMSWITCHTABLE, 0x1159)                       \
    ENUM_VALUE(S_CALLEES, 0x115a)                              \
    ENUM_VALUE(S_CALLERS, 0x115b)                              \
    ENUM_VALUE(S_POGODATA, 0x115c)                             \
    ENUM_VALUE(S_INLINESITE2, 0x115d)                          \
    ENUM_VALUE(S_HEAPALLOCSITE, 0x115e)                        \
    ENUM_VALUE(S_MOD_TYPEREF, 0x115f)                          \
    ENUM_VALUE(S_REF_MINIPDB, 0x1160)                          \
    ENUM_VALUE(S_PDBMAP, 0x1161)                               \
    ENUM_VALUE(S_GDATA_HLSL32, 0x1162)                         \
    ENUM_VALUE(S_LDATA_HLSL32, 0x1163)                         \
    ENUM_VALUE(S_GDATA_HLSL32_EX, 0x1164)                      \
    ENUM_VALUE(S_LDATA_HLSL32_EX, 0x1165)                      \
    ENUM_VALUE(S_REF_MINIPDB2, 0x1167)                         \
    ENUM_VALUE(S_INLINEES, 0x1168)                             \
ENUM_END(cv_symbol_type)

CV_SYMBOL_TYPE_ENUM

void cv_symbol_type_print(enum cv_symbol_type type, FILE *stream);

/* ---------- CV PE section offset */

#define CV_PE_SECTION_OFFSET_STRUCT \
STRUCT_DECL(cv_pe_section_offset) \
    FIELD_PRIMITIVE(uint32_t, memory_offset, "%u") \
    FIELD_PRIMITIVE(uint16_t, section_index, "%u") \
STRUCT_END(cv_pe_section_offset)

CV_PE_SECTION_OFFSET_STRUCT

void cv_pe_section_offset_print(struct cv_pe_section_offset *item, uint32_t depth, FILE *stream);
void cv_pe_section_offset_read(struct cv_pe_section_offset *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV obj name symbol */

#define CV_OBJ_NAME_SYMBOL_STRUCT \
STRUCT_DECL(cv_obj_name_symbol) \
    FIELD_PRIMITIVE(uint32_t, signature, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_obj_name_symbol)

CV_OBJ_NAME_SYMBOL_STRUCT

void cv_obj_name_symbol_dispose(struct cv_obj_name_symbol *item);
void cv_obj_name_symbol_print(struct cv_obj_name_symbol *item, uint32_t depth, FILE *stream);
void cv_obj_name_symbol_read(struct cv_obj_name_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV register variable symbol */

#define CV_REGISTER_VARIABLE_SYMBOL_STRUCT \
STRUCT_DECL(cv_register_variable_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_PRIMITIVE(uint16_t, register_index, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_register_variable_symbol)

CV_REGISTER_VARIABLE_SYMBOL_STRUCT

void cv_register_variable_symbol_dispose(struct cv_register_variable_symbol *item);
void cv_register_variable_symbol_print(struct cv_register_variable_symbol *item, uint32_t depth, FILE *stream);
void cv_register_variable_symbol_read(struct cv_register_variable_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV constant symbol */

#define CV_CONSTANT_SYMBOL_STRUCT \
STRUCT_DECL(cv_constant_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_STRUCT(struct tpi_enumerate_variant, value, tpi_enumerate_variant_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_constant_symbol)

CV_CONSTANT_SYMBOL_STRUCT

void cv_constant_symbol_dispose(struct cv_constant_symbol *item);
void cv_constant_symbol_print(struct cv_constant_symbol *item, uint32_t depth, FILE *stream);
void cv_constant_symbol_read(struct cv_constant_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV user defined type symbol */

#define CV_USER_DEFINED_TYPE_SYMBOL_STRUCT \
STRUCT_DECL(cv_user_defined_type_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_user_defined_type_symbol)

CV_USER_DEFINED_TYPE_SYMBOL_STRUCT

void cv_user_defined_type_symbol_dispose(struct cv_user_defined_type_symbol *item);
void cv_user_defined_type_symbol_print(struct cv_user_defined_type_symbol *item, uint32_t depth, FILE *stream);
void cv_user_defined_type_symbol_read(struct cv_user_defined_type_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV multi register entry */

#define CV_MULTI_REGISTER_ENTRY_STRUCT \
STRUCT_DECL(cv_multi_register_entry) \
    FIELD_PRIMITIVE(uint16_t, register_index, "%u") \
    FIELD_PRIMITIVE(char *, register_name, "\"%s\"") \
STRUCT_END(cv_multi_register_entry)

CV_MULTI_REGISTER_ENTRY_STRUCT

void cv_multi_register_entry_dispose(struct cv_multi_register_entry *entry);
void cv_multi_register_entry_print(struct cv_multi_register_entry *entry, uint32_t depth, FILE *stream);
void cv_multi_register_entry_read(struct cv_multi_register_entry *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV multi register variable symbol */

#define CV_MULTI_REGISTER_VARIABLE_SYMBOL_STRUCT \
STRUCT_DECL(cv_multi_register_variable_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, register_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_multi_register_entry *, registers, register_count, cv_multi_register_entry_print) \
STRUCT_END(cv_multi_register_variable_symbol)

CV_MULTI_REGISTER_VARIABLE_SYMBOL_STRUCT

void cv_multi_register_variable_symbol_dispose(struct cv_multi_register_variable_symbol *item);
void cv_multi_register_variable_symbol_print(struct cv_multi_register_variable_symbol *item, uint32_t depth, FILE *stream);
void cv_multi_register_variable_symbol_read(struct cv_multi_register_variable_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV data symbol */

#define CV_DATA_SYMBOL_STRUCT \
STRUCT_DECL(cv_data_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_data_symbol)

CV_DATA_SYMBOL_STRUCT

void cv_data_symbol_dispose(struct cv_data_symbol *item);
void cv_data_symbol_print(struct cv_data_symbol *item, uint32_t depth, FILE *stream);
void cv_data_symbol_read(struct cv_data_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV public symbol flags */

#define CV_PUBLIC_SYMBOL_FLAGS_ENUM \
ENUM_DECL(cv_public_symbol_flags) \
    ENUM_VALUE(CVPSF_CODE, 1 << 0) \
    ENUM_VALUE(CVPSF_FUNCTION, 1 << 1) \
    ENUM_VALUE(CVPSF_MANAGED, 1 << 2) \
    ENUM_VALUE(CVPSF_MSIL, 1 << 3) \
ENUM_END(cv_public_symbol_flags)

CV_PUBLIC_SYMBOL_FLAGS_ENUM

/* ---------- CV public symbol */

#define CV_PUBLIC_SYMBOL_STRUCT \
STRUCT_DECL(cv_public_symbol) \
    FIELD_PRIMITIVE(uint32_t, flags, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_public_symbol)

CV_PUBLIC_SYMBOL_STRUCT

void cv_public_symbol_dispose(struct cv_public_symbol *item);
void cv_public_symbol_print(struct cv_public_symbol *item, uint32_t depth, FILE *stream);
void cv_public_symbol_read(struct cv_public_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV procedure flags */

#define CV_PROCEDURE_FLAGS_ENUM \
ENUM_DECL(cv_procedure_flags) \
    ENUM_VALUE(CV_PFLAG_NOFPO, 0x01) \
    ENUM_VALUE(CV_PFLAG_INT, 0x02) \
    ENUM_VALUE(CV_PFLAG_FAR, 0x04) \
    ENUM_VALUE(CV_PFLAG_NEVER, 0x08) \
    ENUM_VALUE(CV_PFLAG_NOTREACHED, 0x10) \
    ENUM_VALUE(CV_PFLAG_CUST_CALL, 0x20) \
    ENUM_VALUE(CV_PFLAG_NOINLINE, 0x40) \
    ENUM_VALUE(CV_PFLAG_OPTDBGINFO, 0x80) \
ENUM_END(cv_procedure_flags)

CV_PROCEDURE_FLAGS_ENUM

/* ---------- CV procedure symbol */

#define CV_PROCEDURE_SYMBOL_STRUCT \
STRUCT_DECL(cv_procedure_symbol) \
    FIELD_PRIMITIVE(uint32_t, parent_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, end_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, next_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, code_block_length, "%u") \
    FIELD_PRIMITIVE(uint32_t, debug_start_offset, "%u") \
    FIELD_PRIMITIVE(uint32_t, debug_end_offset, "%u") \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(uint8_t, flags, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_procedure_symbol)

CV_PROCEDURE_SYMBOL_STRUCT

void cv_procedure_symbol_dispose(struct cv_procedure_symbol *item);
void cv_procedure_symbol_print(struct cv_procedure_symbol *item, uint32_t depth, FILE *stream);
void cv_procedure_symbol_read(struct cv_procedure_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV thread storage symbol */

#define CV_THREAD_STORAGE_SYMBOL_STRUCT \
STRUCT_DECL(cv_thread_storage_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_thread_storage_symbol)

CV_THREAD_STORAGE_SYMBOL_STRUCT

void cv_thread_storage_symbol_dispose(struct cv_thread_storage_symbol *item);
void cv_thread_storage_symbol_print(struct cv_thread_storage_symbol *item, uint32_t depth, FILE *stream);
void cv_thread_storage_symbol_read(struct cv_thread_storage_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV source language */

#define CV_SOURCE_LANGUAGE_ENUM \
ENUM_DECL(cv_source_language) \
    ENUM_VALUE(CV_CFL_C, 0x00) \
    ENUM_VALUE(CV_CFL_CXX, 0x01) \
    ENUM_VALUE(CV_CFL_FORTRAN, 0x02) \
    ENUM_VALUE(CV_CFL_MASM, 0x03) \
    ENUM_VALUE(CV_CFL_PASCAL, 0x04) \
    ENUM_VALUE(CV_CFL_BASIC, 0x05) \
    ENUM_VALUE(CV_CFL_COBOL, 0x06) \
    ENUM_VALUE(CV_CFL_LINK, 0x07) \
    ENUM_VALUE(CV_CFL_CVTRES, 0x08) \
    ENUM_VALUE(CV_CFL_CVTPGD, 0x09) \
    ENUM_VALUE(CV_CFL_CSHARP, 0x0A) \
    ENUM_VALUE(CV_CFL_VB, 0x0B) \
    ENUM_VALUE(CV_CFL_ILASM, 0x0C) \
    ENUM_VALUE(CV_CFL_JAVA, 0x0D) \
    ENUM_VALUE(CV_CFL_JSCRIPT, 0x0E) \
    ENUM_VALUE(CV_CFL_MSIL, 0x0F) \
    ENUM_VALUE(CV_CFL_HLSL, 0x10) \
ENUM_END(cv_source_language)

CV_SOURCE_LANGUAGE_ENUM

void cv_source_language_print(enum cv_source_language language, FILE *stream);

/* ---------- CV compiler version */

#define CV_COMPILER_VERSION_STRUCT \
STRUCT_DECL(cv_compiler_version) \
    FIELD_PRIMITIVE(uint16_t, major, "%u") \
    FIELD_PRIMITIVE(uint16_t, minor, "%u") \
    FIELD_PRIMITIVE(uint16_t, build, "%u") \
    FIELD_PRIMITIVE(uint16_t, qfe, "%u") \
STRUCT_END(cv_compiler_version)

CV_COMPILER_VERSION_STRUCT

void cv_compiler_version_print(struct cv_compiler_version *item, uint32_t depth, FILE *stream);
void cv_compiler_version_read(struct cv_compiler_version *item, uint32_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV compile flags */

/* ---------- CV compile flags */

#define CV_COMPILE_FLAGS_STRUCT \
STRUCT_DECL(cv_compile_flags) \
    FIELD_PRIMITIVE_BITS_FMT(uint32_t, language, 8, cv_source_language_print) /* language index */ \
    FIELD_PRIMITIVE_BITS(uint32_t, edit_and_continue, 1, "%u") /* compiled for E/C */ \
    FIELD_PRIMITIVE_BITS(uint32_t, no_debug_info, 1, "%u") /* not compiled with debug info */ \
    FIELD_PRIMITIVE_BITS(uint32_t, link_time_codegen, 1, "%u") /* compiled with LTCG */ \
    FIELD_PRIMITIVE_BITS(uint32_t, no_data_align, 1, "%u") /* compiled with -Bzalign */ \
    FIELD_PRIMITIVE_BITS(uint32_t, managed_present, 1, "%u") /* managed code/data present */ \
    FIELD_PRIMITIVE_BITS(uint32_t, security_checks, 1, "%u") /* compiled with /GS */ \
    FIELD_PRIMITIVE_BITS(uint32_t, hot_patch, 1, "%u") /* compiled with /hotpatch */ \
    FIELD_PRIMITIVE_BITS(uint32_t, cvtcil, 1, "%u") /* converted with CVTCIL */ \
    FIELD_PRIMITIVE_BITS(uint32_t, msil_module, 1, "%u") /* MSIL netmodule */ \
    FIELD_PRIMITIVE_BITS(uint32_t, sdl, 1, "%u") /* compiled with /sdl */ \
    FIELD_PRIMITIVE_BITS(uint32_t, pgo, 1, "%u") /* compiled with /ltcg:pgo or pgu */ \
    FIELD_PRIMITIVE_BITS(uint32_t, exp, 1, "%u") /* .exp module */ \
    FIELD_PRIMITIVE_BITS(uint32_t, pad, 12, "%u") /* reserved, must be 0 */ \
STRUCT_END(cv_compile_flags)

CV_COMPILE_FLAGS_STRUCT
static_assert(sizeof(struct cv_compile_flags) == sizeof(uint32_t), "invalid cv_compile_flags size");

void cv_compile_flags_print(struct cv_compile_flags *item, uint32_t depth, FILE *stream);

/* ---------- CV compile flags symbol */

#define CV_COMPILE_FLAGS_SYMBOL_STRUCT \
STRUCT_DECL(cv_compile_flags_symbol) \
    FIELD_STRUCT(struct cv_compile_flags, flags, cv_compile_flags_print) \
    FIELD_PRIMITIVE_FMT(uint16_t, cpu_type, cv_cpu_type_print) \
    FIELD_STRUCT(struct cv_compiler_version, frontend_version, cv_compiler_version_print) \
    FIELD_STRUCT(struct cv_compiler_version, backend_version, cv_compiler_version_print) \
    FIELD_PRIMITIVE(char *, version_string, "\"%s\"") \
    FIELD_PRIMITIVE(uint32_t, string_count, "%u") \
    FIELD_PRIMITIVE_DYNAMIC_ARRAY(char **, strings, string_count, "\"%s\"") \
STRUCT_END(cv_compile_flags_symbol)

CV_COMPILE_FLAGS_SYMBOL_STRUCT

void cv_compile_flags_symbol_dispose(struct cv_compile_flags_symbol *item);
void cv_compile_flags_symbol_print(struct cv_compile_flags_symbol *item, uint32_t depth, FILE *stream);
void cv_compile_flags_symbol_read(struct cv_compile_flags_symbol *item, uint16_t symbol_type, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV using namespace symbol */

#define CV_USING_NAMESPACE_SYMBOL_STRUCT \
STRUCT_DECL(cv_using_namespace_symbol) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_using_namespace_symbol)

CV_USING_NAMESPACE_SYMBOL_STRUCT

void cv_using_namespace_symbol_dispose(struct cv_using_namespace_symbol *item);
void cv_using_namespace_symbol_print(struct cv_using_namespace_symbol *item, uint32_t depth, FILE *stream);
void cv_using_namespace_symbol_read(struct cv_using_namespace_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV procedure reference symbol */

#define CV_PROCEDURE_REFERENCE_SYMBOL_STRUCT \
STRUCT_DECL(cv_procedure_reference_symbol) \
    FIELD_PRIMITIVE(uint32_t, sum_name, "%u") \
    FIELD_PRIMITIVE(uint32_t, symbol_index, "%u") \
    FIELD_PRIMITIVE(uint16_t, module_index, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_procedure_reference_symbol)

CV_PROCEDURE_REFERENCE_SYMBOL_STRUCT

void cv_procedure_reference_symbol_dispose(struct cv_procedure_reference_symbol *item);
void cv_procedure_reference_symbol_print(struct cv_procedure_reference_symbol *item, uint32_t depth, FILE *stream);
void cv_procedure_reference_symbol_read(struct cv_procedure_reference_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV data reference symbol */

#define CV_DATA_REFERENCE_SYMBOL_STRUCT \
STRUCT_DECL(cv_data_reference_symbol) \
    FIELD_PRIMITIVE(uint32_t, sum_name, "%u") \
    FIELD_PRIMITIVE(uint32_t, symbol_index, "%u") \
    FIELD_PRIMITIVE(uint16_t, module_index, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_data_reference_symbol)

CV_DATA_REFERENCE_SYMBOL_STRUCT

void cv_data_reference_symbol_dispose(struct cv_data_reference_symbol *item);
void cv_data_reference_symbol_print(struct cv_data_reference_symbol *item, uint32_t depth, FILE *stream);
void cv_data_reference_symbol_read(struct cv_data_reference_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV annotation reference symbol */

#define CV_ANNOTATION_REFERENCE_SYMBOL_STRUCT \
STRUCT_DECL(cv_annotation_reference_symbol) \
    FIELD_PRIMITIVE(uint32_t, sum_name, "%u") \
    FIELD_PRIMITIVE(uint32_t, symbol_index, "%u") \
    FIELD_PRIMITIVE(uint16_t, module_index, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_annotation_reference_symbol)

CV_ANNOTATION_REFERENCE_SYMBOL_STRUCT

void cv_annotation_reference_symbol_dispose(struct cv_annotation_reference_symbol *item);
void cv_annotation_reference_symbol_print(struct cv_annotation_reference_symbol *item, uint32_t depth, FILE *stream);
void cv_annotation_reference_symbol_read(struct cv_annotation_reference_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV trampoline type */

#define CV_TRAMPOLINE_TYPE_ENUM \
ENUM_DECL(cv_trampoline_type) \
    ENUM_VALUE(CV_TRAMPOLINE_TYPE_INCREMENTAL) \
    ENUM_VALUE(CV_TRAMPOLINE_TYPE_BRANCH_ISLAND) \
ENUM_END(cv_trampoline_type)

CV_TRAMPOLINE_TYPE_ENUM

void cv_trampoline_type_print(enum cv_trampoline_type type, FILE *stream);

/* ---------- CV trampoline symbol */

#define CV_TRAMPOLINE_SYMBOL_STRUCT \
STRUCT_DECL(cv_trampoline_symbol) \
    FIELD_PRIMITIVE(uint16_t, type, "%u") \
    FIELD_PRIMITIVE(uint16_t, size, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, thunk_offset, cv_pe_section_offset_print) \
    FIELD_STRUCT(struct cv_pe_section_offset, target_offset, cv_pe_section_offset_print) \
STRUCT_END(cv_trampoline_symbol)

CV_TRAMPOLINE_SYMBOL_STRUCT

void cv_trampoline_symbol_print(struct cv_trampoline_symbol *item, uint32_t depth, FILE *stream);
void cv_trampoline_symbol_read(struct cv_trampoline_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV export symbol */

#define CV_EXPORT_SYMBOL_STRUCT \
STRUCT_DECL(cv_export_symbol) \
    FIELD_PRIMITIVE(uint16_t, ordinal, "%u") \
    FIELD_PRIMITIVE(uint16_t, flags, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_export_symbol)

CV_EXPORT_SYMBOL_STRUCT

void cv_export_symbol_dispose(struct cv_export_symbol *item);
void cv_export_symbol_print(struct cv_export_symbol *item, uint32_t depth, FILE *stream);
void cv_export_symbol_read(struct cv_export_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV local symbol */

#define CV_LOCAL_SYMBOL_STRUCT \
STRUCT_DECL(cv_local_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_PRIMITIVE(uint16_t, flags, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_local_symbol)

CV_LOCAL_SYMBOL_STRUCT

void cv_local_symbol_dispose(struct cv_local_symbol *item);
void cv_local_symbol_print(struct cv_local_symbol *item, uint32_t depth, FILE *stream);
void cv_local_symbol_read(struct cv_local_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV build info symbol */

#define CV_BUILD_INFO_SYMBOL_STRUCT \
STRUCT_DECL(cv_build_info_symbol) \
    FIELD_PRIMITIVE(uint32_t, id_index, "%u") \
STRUCT_END(cv_build_info_symbol)

CV_BUILD_INFO_SYMBOL_STRUCT

void cv_build_info_symbol_print(struct cv_build_info_symbol *item, uint32_t depth, FILE *stream);
void cv_build_info_symbol_read(struct cv_build_info_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV annotation type */

#define CV_ANNOTATION_TYPE_ENUM \
ENUM_DECL(cv_annotation_type) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_EOF) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CODE_OFFSET) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_CODE_OFFSET_BASE) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_CODE_OFFSET) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_CODE_LENGTH) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_FILE) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_LINE_OFFSET) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_LINE_END_DELTA) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_RANGE_KIND) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_COLUMN_START) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_COLUMN_END_DELTA) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_CODE_AND_LINE_OFFSETS) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_CODE_LENGTH_AND_CODE_OFFSET) \
    ENUM_VALUE(CV_ANNOTATION_TYPE_CHANGE_COLUMN_END) \
ENUM_END(cv_annotation_type)

CV_ANNOTATION_TYPE_ENUM

void cv_annotation_type_print(enum cv_annotation_type type, FILE *stream);

/* ---------- CV annotation code and line offsets */

#define CV_ANNOTATION_CODE_AND_LINE_OFFSETS_STRUCT \
STRUCT_DECL(cv_annotation_code_and_line_offsets) \
    FIELD_PRIMITIVE(uint32_t, code_offset, "%u") \
    FIELD_PRIMITIVE(int32_t, line_offset, "%u") \
STRUCT_END(cv_annotation_code_and_line_offsets)

CV_ANNOTATION_CODE_AND_LINE_OFFSETS_STRUCT

void cv_annotation_code_and_line_offsets_print(struct cv_annotation_code_and_line_offsets *item, uint32_t depth, FILE *stream);
void cv_annotation_code_and_line_offsets_read(struct cv_annotation_code_and_line_offsets *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV annotation code length and offset */

#define CV_ANNOTATION_CODE_LENGTH_AND_OFFSET_STRUCT \
STRUCT_DECL(cv_annotation_code_length_and_offset) \
    FIELD_PRIMITIVE(uint32_t, code_length, "%u") \
    FIELD_PRIMITIVE(uint32_t, code_offset, "%u") \
STRUCT_END(cv_annotation_code_length_and_offset)

CV_ANNOTATION_CODE_LENGTH_AND_OFFSET_STRUCT

void cv_annotation_code_length_and_offset_print(struct cv_annotation_code_length_and_offset *item, uint32_t depth, FILE *stream);

/* ---------- CV annotation */

#define CV_ANNOTATION_STRUCT \
STRUCT_DECL(cv_annotation) \
    FIELD_PRIMITIVE_FMT(enum cv_annotation_type, type, cv_annotation_type_print) \
    FIELD_UNION_DECL() \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, code_offset, type, CV_ANNOTATION_TYPE_CODE_OFFSET, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_code_offset_base, type, CV_ANNOTATION_TYPE_CHANGE_CODE_OFFSET_BASE, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_code_offset, type, CV_ANNOTATION_TYPE_CHANGE_CODE_OFFSET, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_code_length, type, CV_ANNOTATION_TYPE_CHANGE_CODE_LENGTH, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_file, type, CV_ANNOTATION_TYPE_CHANGE_FILE, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(int32_t, change_line_offset, type, CV_ANNOTATION_TYPE_CHANGE_LINE_OFFSET, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_line_end_delta, type, CV_ANNOTATION_TYPE_CHANGE_LINE_END_DELTA, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_range_kind, type, CV_ANNOTATION_TYPE_CHANGE_RANGE_KIND, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_column_start, type, CV_ANNOTATION_TYPE_CHANGE_COLUMN_START, "%u") \
        FIELD_UNION_FIELD_PRIMITIVE(int32_t, change_column_end_delta, type, CV_ANNOTATION_TYPE_CHANGE_COLUMN_END_DELTA, "%u") \
        FIELD_UNION_FIELD_STRUCT(struct cv_annotation_code_and_line_offsets, change_code_and_line_offsets, type, CV_ANNOTATION_TYPE_CHANGE_CODE_AND_LINE_OFFSETS, cv_annotation_code_and_line_offsets_print) \
        FIELD_UNION_FIELD_STRUCT(struct cv_annotation_code_length_and_offset, change_code_length_and_code_offset, type, CV_ANNOTATION_TYPE_CHANGE_CODE_LENGTH_AND_CODE_OFFSET, cv_annotation_code_length_and_offset_print) \
        FIELD_UNION_FIELD_PRIMITIVE(uint32_t, change_column_end, type, CV_ANNOTATION_TYPE_CHANGE_COLUMN_END, "%u") \
    FIELD_UNION_END() \
STRUCT_END(cv_annotation)

CV_ANNOTATION_STRUCT

void cv_annotation_print(struct cv_annotation *item, uint32_t depth, FILE *stream);
void cv_annotation_read(struct cv_annotation *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV annotations */

#define CV_ANNOTATIONS_STRUCT \
STRUCT_DECL(cv_annotations) \
    FIELD_PRIMITIVE(uint32_t, count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_annotation *, annotations, count, cv_annotation_print) \
STRUCT_END(cv_annotations)

CV_ANNOTATIONS_STRUCT

void cv_annotations_dispose(struct cv_annotations *item);
void cv_annotations_print(struct cv_annotations *item, uint32_t depth, FILE *stream);
void cv_annotations_read(struct cv_annotations *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, uint32_t size, struct memory_stream *file_stream);

/* ---------- CV inline site symbol */

#define CV_INLINE_SITE_SYMBOL_STRUCT \
STRUCT_DECL(cv_inline_site_symbol) \
    FIELD_PRIMITIVE(uint32_t, parent_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, end_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, inlinee_id_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, invocation_count, "%u") \
    FIELD_STRUCT(struct cv_annotations, annotations, cv_annotations_print) \
STRUCT_END(cv_inline_site_symbol)

CV_INLINE_SITE_SYMBOL_STRUCT

void cv_inline_site_symbol_dispose(struct cv_inline_site_symbol *item);
void cv_inline_site_symbol_print(struct cv_inline_site_symbol *item, uint32_t depth, FILE *stream);
void cv_inline_site_symbol_read(struct cv_inline_site_symbol *item, uint16_t symbol_type, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV label symbol */

#define CV_LABEL_SYMBOL_STRUCT \
STRUCT_DECL(cv_label_symbol) \
    FIELD_STRUCT(struct cv_pe_section_offset, section_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(uint8_t, flags, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_label_symbol)

CV_LABEL_SYMBOL_STRUCT

void cv_label_symbol_dispose(struct cv_label_symbol *item);
void cv_label_symbol_print(struct cv_label_symbol *item, uint32_t depth, FILE *stream);
void cv_label_symbol_read(struct cv_label_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV block symbol */

#define CV_BLOCK_SYMBOL_STRUCT \
STRUCT_DECL(cv_block_symbol) \
    FIELD_PRIMITIVE(uint32_t, parent_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, end_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, length, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, section_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_block_symbol)

CV_BLOCK_SYMBOL_STRUCT

void cv_block_symbol_dispose(struct cv_block_symbol *item);
void cv_block_symbol_print(struct cv_block_symbol *item, uint32_t depth, FILE *stream);
void cv_block_symbol_read(struct cv_block_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV register relative symbol */

#define CV_REGISTER_RELATIVE_SYMBOL_STRUCT \
STRUCT_DECL(cv_register_relative_symbol) \
    FIELD_PRIMITIVE(int32_t, offset, "%i") \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_PRIMITIVE(uint16_t, register_index, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_register_relative_symbol)

CV_REGISTER_RELATIVE_SYMBOL_STRUCT

void cv_register_relative_symbol_dispose(struct cv_register_relative_symbol *item);
void cv_register_relative_symbol_print(struct cv_register_relative_symbol *item, uint32_t depth, FILE *stream);
void cv_register_relative_symbol_read(struct cv_register_relative_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV thunk symbol */

#define CV_THUNK_SYMBOL_STRUCT \
STRUCT_DECL(cv_thunk_symbol) \
    FIELD_PRIMITIVE(uint32_t, parent_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, end_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, next_symbol_index, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, section_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(uint16_t, length, "%u") \
    FIELD_PRIMITIVE(uint8_t, ordinal, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_thunk_symbol)

CV_THUNK_SYMBOL_STRUCT

void cv_thunk_symbol_dispose(struct cv_thunk_symbol *item);
void cv_thunk_symbol_print(struct cv_thunk_symbol *item, uint32_t depth, FILE *stream);
void cv_thunk_symbol_read(struct cv_thunk_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV separated code symbol */

#define CV_SEPARATED_CODE_SYMBOL_STRUCT \
STRUCT_DECL(cv_separated_code_symbol) \
    FIELD_PRIMITIVE(uint32_t, parent_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, end_symbol_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, length, "%u") \
    FIELD_PRIMITIVE(uint32_t, flags, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, section_offset, cv_pe_section_offset_print) \
    FIELD_STRUCT(struct cv_pe_section_offset, parent_section_offset, cv_pe_section_offset_print) \
STRUCT_END(cv_separated_code_symbol)

CV_SEPARATED_CODE_SYMBOL_STRUCT

void cv_separated_code_symbol_print(struct cv_separated_code_symbol *item, uint32_t depth, FILE *stream);
void cv_separated_code_symbol_read(struct cv_separated_code_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV cookie type */

#define CV_COOKIE_TYPE_ENUM \
ENUM_DECL(cv_cookie_type) \
    ENUM_VALUE(CV_COOKIETYPE_COPY) \
    ENUM_VALUE(CV_COOKIETYPE_XOR_SP) \
    ENUM_VALUE(CV_COOKIETYPE_XOR_BP) \
    ENUM_VALUE(CV_COOKIETYPE_XOR_R13) \
ENUM_END(cv_cookie_type)

CV_COOKIE_TYPE_ENUM

void cv_cookie_type_print(enum cv_cookie_type item, FILE *stream);

/* ---------- CV frame cookie symbol */

#define CV_FRAME_COOKIE_SYMBOL_STRUCT \
STRUCT_DECL(cv_frame_cookie_symbol) \
    FIELD_PRIMITIVE(int32_t, frame_relative_offset, "%i") \
    FIELD_PRIMITIVE(uint16_t, register_index, "%u") \
    FIELD_PRIMITIVE_FMT(uint8_t, cookie_type, cv_cookie_type_print) \
    FIELD_PRIMITIVE(uint8_t, flags, "%u") \
STRUCT_END(cv_frame_cookie_symbol)

CV_FRAME_COOKIE_SYMBOL_STRUCT

void cv_frame_cookie_symbol_print(struct cv_frame_cookie_symbol *item, uint32_t depth, FILE *stream);
void cv_frame_cookie_symbol_read(struct cv_frame_cookie_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV frame proc flags */

#define CV_FRAME_PROC_FLAGS_STRUCT \
STRUCT_DECL(cv_frame_proc_flags) \
    FIELD_PRIMITIVE_BITS(uint32_t, has_alloca, 1, "%u") /* function uses _alloca() */ \
    FIELD_PRIMITIVE_BITS(uint32_t, has_setjmp, 1, "%u") /* function uses setjmp() */ \
    FIELD_PRIMITIVE_BITS(uint32_t, has_longjmp, 1, "%u") /* function uses longjmp() */ \
    FIELD_PRIMITIVE_BITS(uint32_t, has_inline_asm, 1, "%u") /* function uses inline asm */ \
    FIELD_PRIMITIVE_BITS(uint32_t, has_eh, 1, "%u") /* function has EH states */ \
    FIELD_PRIMITIVE_BITS(uint32_t, is_inline, 1, "%u") /* function was speced as inline */ \
    FIELD_PRIMITIVE_BITS(uint32_t, has_seh, 1, "%u") /* function has SEH */ \
    FIELD_PRIMITIVE_BITS(uint32_t, naked, 1, "%u") /* function is __declspec(naked) */ \
    FIELD_PRIMITIVE_BITS(uint32_t, security_checks, 1, "%u") /* function has buffer security check introduced by /GS. */ \
    FIELD_PRIMITIVE_BITS(uint32_t, async_eh, 1, "%u") /* function compiled with /EHa */ \
    FIELD_PRIMITIVE_BITS(uint32_t, gs_no_stack_ordering, 1, "%u") /* function has /GS buffer checks, but stack ordering couldn't be done */ \
    FIELD_PRIMITIVE_BITS(uint32_t, was_inlined, 1, "%u") /* function was inlined within another function */ \
    FIELD_PRIMITIVE_BITS(uint32_t, gs_check, 1, "%u") /* function is __declspec(strict_gs_check) */ \
    FIELD_PRIMITIVE_BITS(uint32_t, safe_buffers, 1, "%u") /* function is __declspec(safebuffers) */ \
    FIELD_PRIMITIVE_BITS(uint32_t, encoded_local_base_pointer, 2, "%u") /* record function's local pointer explicitly. */ \
    FIELD_PRIMITIVE_BITS(uint32_t, encoded_param_base_pointer, 2, "%u") /* record function's parameter pointer explicitly. */ \
    FIELD_PRIMITIVE_BITS(uint32_t, pogo_on, 1, "%u") /* function was compiled with PGO/PGU */ \
    FIELD_PRIMITIVE_BITS(uint32_t, valid_counts, 1, "%u") /* Do we have valid Pogo counts? */ \
    FIELD_PRIMITIVE_BITS(uint32_t, opt_speed, 1, "%u") /* Did we optimize for speed? */ \
    FIELD_PRIMITIVE_BITS(uint32_t, guard_cf, 1, "%u") /* function contains CFG checks (and no write checks) */ \
    FIELD_PRIMITIVE_BITS(uint32_t, guard_cfw, 1, "%u") /* function contains CFW checks and/or instrumentation */ \
    FIELD_PRIMITIVE_BITS(uint32_t, pad, 9, "%u") /* must be zero */ \
STRUCT_END(cv_frame_proc_flags)

CV_FRAME_PROC_FLAGS_STRUCT
static_assert(sizeof(struct cv_frame_proc_flags) == sizeof(uint32_t), "invalid cv_frame_proc_flags size");

void cv_frame_proc_flags_print(struct cv_frame_proc_flags *item, uint32_t depth, FILE *stream);

/* ---------- CV frame proc symbol */

#define CV_FRAME_PROC_SYMBOL_STRUCT \
STRUCT_DECL(cv_frame_proc_symbol) \
    FIELD_PRIMITIVE(uint32_t, frame_size, "%u") \
    FIELD_PRIMITIVE(uint32_t, padding_size, "%u") \
    FIELD_PRIMITIVE(uint32_t, padding_offset, "%u") \
    FIELD_PRIMITIVE(uint32_t, callee_save_registers_size, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, exception_handler_offset, cv_pe_section_offset_print) \
    FIELD_STRUCT(struct cv_frame_proc_flags, flags, cv_frame_proc_flags_print) \
STRUCT_END(cv_frame_proc_symbol)

CV_FRAME_PROC_SYMBOL_STRUCT

void cv_frame_proc_symbol_print(struct cv_frame_proc_symbol *item, uint32_t depth, FILE *stream);
void cv_frame_proc_symbol_read(struct cv_frame_proc_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV call site info symbol */

#define CV_CALL_SITE_INFO_SYMBOL_STRUCT \
STRUCT_DECL(cv_call_site_info_symbol) \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(uint16_t, padding, "%u") \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
STRUCT_END(cv_call_site_info_symbol)

CV_CALL_SITE_INFO_SYMBOL_STRUCT

void cv_call_site_info_symbol_print(struct cv_call_site_info_symbol *item, uint32_t depth, FILE *stream);
void cv_call_site_info_symbol_read(struct cv_call_site_info_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV heap alloc site symbol */

#define CV_HEAP_ALLOC_SITE_SYMBOL_STRUCT \
STRUCT_DECL(cv_heap_alloc_site_symbol) \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) /* offset of call site */ \
    FIELD_PRIMITIVE(uint16_t, instruction_size, "%u") /* length of heap allocation call instruction */ \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") /* type index describing function signature */ \
STRUCT_END(cv_heap_alloc_site_symbol)

CV_HEAP_ALLOC_SITE_SYMBOL_STRUCT

void cv_heap_alloc_site_symbol_print(struct cv_heap_alloc_site_symbol *item, uint32_t depth, FILE *stream);
void cv_heap_alloc_site_symbol_read(struct cv_heap_alloc_site_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV env block flags */

#define CV_ENV_BLOCK_FLAGS_STRUCT \
STRUCT_DECL(cv_env_block_flags) \
    FIELD_PRIMITIVE_BITS(uint8_t, rev, 1, "%u") \
    FIELD_PRIMITIVE_BITS(uint8_t, pad, 7, "%u") \
STRUCT_END(cv_env_block_flags)

CV_ENV_BLOCK_FLAGS_STRUCT
static_assert(sizeof(struct cv_env_block_flags) == sizeof(uint8_t), "invalid cv_env_block_flags size");

void cv_env_block_flags_print(struct cv_env_block_flags *item, uint32_t depth, FILE *stream);

/* ---------- CV env block symbol */

#define CV_ENV_BLOCK_SYMBOL_STRUCT \
STRUCT_DECL(cv_env_block_symbol) \
    FIELD_STRUCT(struct cv_env_block_flags, flags, cv_env_block_flags_print) \
    FIELD_PRIMITIVE(uint32_t, string_count, "%u") \
    FIELD_PRIMITIVE_DYNAMIC_ARRAY(char **, strings, string_count, "\"%s\"") \
STRUCT_END(cv_env_block_symbol)

CV_ENV_BLOCK_SYMBOL_STRUCT

void cv_env_block_symbol_dispose(struct cv_env_block_symbol *item);
void cv_env_block_symbol_print(struct cv_env_block_symbol *item, uint32_t depth, FILE *stream);
void cv_env_block_symbol_read(struct cv_env_block_symbol *item, uint16_t symbol_type, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV local variable flags */

#define CV_LOCAL_VARIABLE_FLAGS_STRUCT \
STRUCT_DECL(cv_local_variable_flags) \
    FIELD_PRIMITIVE_BITS(uint16_t, is_parameter, 1, "%u") /* variable is a parameter */ \
    FIELD_PRIMITIVE_BITS(uint16_t, address_taken, 1, "%u") /* address is taken */ \
    FIELD_PRIMITIVE_BITS(uint16_t, compiler_generated, 1, "%u") /* variable is compiler generated */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_aggregate, 1, "%u") /* the symbol is splitted in temporaries, which are treated by compiler as  independent entities */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_aggregated, 1, "%u") /* Counterpart of fIsAggregate - tells that it is a part of a fIsAggregate symbol */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_aliased, 1, "%u") /* variable has multiple simultaneous lifetimes */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_alias, 1, "%u") /* represents one of the multiple simultaneous lifetimes */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_return_value, 1, "%u") /* represents a function return value */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_optimized_out, 1, "%u") /* variable has no lifetimes */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_enregistered_glob, 1, "%u") /* variable is an enregistered global */ \
    FIELD_PRIMITIVE_BITS(uint16_t, is_enregistered_stat, 1, "%u") /* variable is an enregistered static */ \
    FIELD_PRIMITIVE_BITS(uint16_t, unused, 5, "%u") /* must be zero */ \
STRUCT_END(cv_local_variable_flags)

CV_LOCAL_VARIABLE_FLAGS_STRUCT

void cv_local_variable_flags_print(struct cv_local_variable_flags *item, uint32_t depth, FILE *stream);

/* ---------- CV file static symbol */

#define CV_FILE_STATIC_SYMBOL_STRUCT \
STRUCT_DECL(cv_file_static_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, module_filename_string_index, "%u") \
    FIELD_STRUCT(struct cv_local_variable_flags, flags, cv_local_variable_flags_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_file_static_symbol)

CV_FILE_STATIC_SYMBOL_STRUCT

void cv_file_static_symbol_print(struct cv_file_static_symbol *item, uint32_t depth, FILE *stream);
void cv_file_static_symbol_read(struct cv_file_static_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV section symbol */

#define CV_SECTION_SYMBOL_STRUCT \
STRUCT_DECL(cv_section_symbol) \
    FIELD_PRIMITIVE(uint16_t, isec, "%u") \
    FIELD_PRIMITIVE(uint8_t, align, "%u") \
    FIELD_PRIMITIVE(uint8_t, bReserved, "%u") \
    FIELD_PRIMITIVE(uint32_t, rva, "%u") \
    FIELD_PRIMITIVE(uint32_t, cb, "%u") \
    FIELD_PRIMITIVE(uint32_t, characteristics, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_section_symbol)

CV_SECTION_SYMBOL_STRUCT

void cv_section_symbol_dispose(struct cv_section_symbol *item);
void cv_section_symbol_print(struct cv_section_symbol *item, uint32_t depth, FILE *stream);
void cv_section_symbol_read(struct cv_section_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV coff group symbol */

#define CV_COFF_GROUP_SYMBOL_STRUCT \
STRUCT_DECL(cv_coff_group_symbol) \
    FIELD_PRIMITIVE(uint32_t, cb, "%u") \
    FIELD_PRIMITIVE(uint32_t, characteristics, "%u") \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_coff_group_symbol)

CV_COFF_GROUP_SYMBOL_STRUCT

void cv_coff_group_symbol_dispose(struct cv_coff_group_symbol *item);
void cv_coff_group_symbol_print(struct cv_coff_group_symbol *item, uint32_t depth, FILE *stream);
void cv_coff_group_symbol_read(struct cv_coff_group_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV annotation symbol */

#define CV_ANNOTATION_SYMBOL_STRUCT \
STRUCT_DECL(cv_annotation_symbol) \
    FIELD_STRUCT(struct cv_pe_section_offset, code_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(uint16_t, string_count, "%u") \
    FIELD_PRIMITIVE_DYNAMIC_ARRAY(char **, strings, string_count, "\"%s\"") \
STRUCT_END(cv_annotation_symbol)

CV_ANNOTATION_SYMBOL_STRUCT

void cv_annotation_symbol_dispose(struct cv_annotation_symbol *item);
void cv_annotation_symbol_print(struct cv_annotation_symbol *item, uint32_t depth, FILE *stream);
void cv_annotation_symbol_read(struct cv_annotation_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV address range */

#define CV_ADDRESS_RANGE_STRUCT \
STRUCT_DECL(cv_address_range) \
    FIELD_STRUCT(struct cv_pe_section_offset, start_offset, cv_pe_section_offset_print) \
    FIELD_PRIMITIVE(uint16_t, length, "%u") \
STRUCT_END(cv_address_range)

CV_ADDRESS_RANGE_STRUCT

void cv_address_range_print(struct cv_address_range *item, uint32_t depth, FILE *stream);
void cv_address_range_read(struct cv_address_range *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV address gap */

#define CV_ADDRESS_GAP_STRUCT \
STRUCT_DECL(cv_address_gap) \
    FIELD_PRIMITIVE(uint16_t, start_offset, "%u") \
    FIELD_PRIMITIVE(uint16_t, length, "%u") \
STRUCT_END(cv_address_gap)

CV_ADDRESS_GAP_STRUCT

void cv_address_gap_print(struct cv_address_gap *item, uint32_t depth, FILE *stream);

/* ---------- CV def range symbol */

#define CV_DEF_RANGE_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_symbol) \
    FIELD_PRIMITIVE(uint32_t, program_index, "%u") \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
STRUCT_END(cv_def_range_symbol)

CV_DEF_RANGE_SYMBOL_STRUCT

void cv_def_range_symbol_dispose(struct cv_def_range_symbol *item);
void cv_def_range_symbol_print(struct cv_def_range_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_symbol_read(struct cv_def_range_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV def range subfield symbol */

#define CV_DEF_RANGE_SUBFIELD_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_subfield_symbol) \
    FIELD_PRIMITIVE(uint32_t, program_index, "%u") \
    FIELD_PRIMITIVE(uint32_t, parent_offset, "%u") \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
STRUCT_END(cv_def_range_subfield_symbol)

CV_DEF_RANGE_SUBFIELD_SYMBOL_STRUCT

void cv_def_range_subfield_symbol_dispose(struct cv_def_range_subfield_symbol *item);
void cv_def_range_subfield_symbol_print(struct cv_def_range_subfield_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_subfield_symbol_read(struct cv_def_range_subfield_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV range attributes */

#define CV_RANGE_ATTRIBUTES_STRUCT \
STRUCT_DECL(cv_range_attributes) \
    FIELD_PRIMITIVE_BITS(uint16_t, maybe, 1, "%u") \
    FIELD_PRIMITIVE_BITS(uint16_t, padding, 15, "%u") \
STRUCT_END(cv_range_attributes)

CV_RANGE_ATTRIBUTES_STRUCT
static_assert(sizeof(struct cv_range_attributes) == sizeof(uint16_t), "invalid cv_range_attributes size");

void cv_range_attributes_print(struct cv_range_attributes *item, uint32_t depth, FILE *stream);

/* ---------- CV def range register symbol */

#define CV_DEF_RANGE_REGISTER_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_register_symbol) \
    FIELD_PRIMITIVE(uint16_t, register_index, "%u") \
    FIELD_STRUCT(struct cv_range_attributes, attributes, cv_range_attributes_print) \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
STRUCT_END(cv_def_range_register_symbol)

CV_DEF_RANGE_REGISTER_SYMBOL_STRUCT

void cv_def_range_register_symbol_dispose(struct cv_def_range_register_symbol *item);
void cv_def_range_register_symbol_print(struct cv_def_range_register_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_register_symbol_read(struct cv_def_range_register_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV def range frame pointer rel symbol */

#define CV_DEF_RANGE_FRAME_POINTER_REL_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_frame_pointer_rel_symbol) \
    FIELD_PRIMITIVE(int32_t, offset, "%u") \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
STRUCT_END(cv_def_range_frame_pointer_rel_symbol)

CV_DEF_RANGE_FRAME_POINTER_REL_SYMBOL_STRUCT

void cv_def_range_frame_pointer_rel_symbol_dispose(struct cv_def_range_frame_pointer_rel_symbol *item);
void cv_def_range_frame_pointer_rel_symbol_print(struct cv_def_range_frame_pointer_rel_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_frame_pointer_rel_symbol_read(struct cv_def_range_frame_pointer_rel_symbol *item, uint16_t symbol_type, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV def range subfield register packed data */

#define CV_OFFSET_PARENT_LENGTH_LIMIT 12

#define CV_DEF_RANGE_SUBFIELD_REGISTER_PACKED_DATA_STRUCT \
STRUCT_DECL(cv_def_range_subfield_register_packed_data) \
    FIELD_PRIMITIVE_BITS(uint32_t, parent_offset, CV_OFFSET_PARENT_LENGTH_LIMIT, "%u") \
    FIELD_PRIMITIVE_BITS(uint32_t, padding, 20, "%u") \
STRUCT_END(cv_def_range_subfield_register_packed_data)

CV_DEF_RANGE_SUBFIELD_REGISTER_PACKED_DATA_STRUCT
static_assert(sizeof(struct cv_def_range_subfield_register_packed_data) == sizeof(uint32_t), "invalid cv_def_range_subfield_register_packed_data size");

void cv_def_range_subfield_register_packed_data_print(struct cv_def_range_subfield_register_packed_data *item, uint32_t depth, FILE *stream);

/* ---------- CV def range subfield register symbol */

#define CV_DEF_RANGE_SUBFIELD_REGISTER_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_subfield_register_symbol) \
    FIELD_PRIMITIVE(uint16_t, register_index, "%u") \
    FIELD_STRUCT(struct cv_range_attributes, attributes, cv_range_attributes_print) \
    FIELD_STRUCT(struct cv_def_range_subfield_register_packed_data, packed_data, cv_def_range_subfield_register_packed_data_print) \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
STRUCT_END(cv_def_range_subfield_register_symbol)

CV_DEF_RANGE_SUBFIELD_REGISTER_SYMBOL_STRUCT

void cv_def_range_subfield_register_symbol_dispose(struct cv_def_range_subfield_register_symbol *item);
void cv_def_range_subfield_register_symbol_print(struct cv_def_range_subfield_register_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_subfield_register_symbol_read(struct cv_def_range_subfield_register_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV def range register rel packed data */

#define CV_DEF_RANGE_REGISTER_REL_PACKED_DATA_STRUCT \
STRUCT_DECL(cv_def_range_register_rel_packed_data) \
    FIELD_PRIMITIVE_BITS(uint16_t, spilled_udt_member, 1, "%u") \
    FIELD_PRIMITIVE_BITS(uint16_t, padding, 3, "%u") \
    FIELD_PRIMITIVE_BITS(uint16_t, parent_offset, CV_OFFSET_PARENT_LENGTH_LIMIT, "%u") \
STRUCT_END(cv_def_range_register_rel_packed_data)

CV_DEF_RANGE_REGISTER_REL_PACKED_DATA_STRUCT
static_assert(sizeof(struct cv_def_range_register_rel_packed_data) == sizeof(uint16_t), "invalid cv_def_range_register_rel_packed_data size");

void cv_def_range_register_rel_packed_data_print(struct cv_def_range_register_rel_packed_data *item, uint32_t depth, FILE *stream);

/* ---------- CV def range register rel symbol */

#define CV_DEF_RANGE_REGISTER_REL_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_register_rel_symbol) \
    FIELD_PRIMITIVE(uint16_t, base_register_index, "%u") \
    FIELD_STRUCT(struct cv_def_range_register_rel_packed_data, packed_data, cv_def_range_register_rel_packed_data_print) \
    FIELD_PRIMITIVE(uint32_t, base_offset, "%u") \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
STRUCT_END(cv_def_range_register_rel_symbol)

CV_DEF_RANGE_REGISTER_REL_SYMBOL_STRUCT

void cv_def_range_register_rel_symbol_dispose(struct cv_def_range_register_rel_symbol *item);
void cv_def_range_register_rel_symbol_print(struct cv_def_range_register_rel_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_register_rel_symbol_read(struct cv_def_range_register_rel_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV hlsl register type */

#define CV_HLSL_REGISTER_TYPE_ENUM \
ENUM_DECL(cv_hlsl_register_type) \
    ENUM_VALUE(CV_HLSLREG_TEMP, 0) \
    ENUM_VALUE(CV_HLSLREG_INPUT, 1) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT, 2) \
    ENUM_VALUE(CV_HLSLREG_INDEXABLE_TEMP, 3) \
    ENUM_VALUE(CV_HLSLREG_IMMEDIATE32, 4) \
    ENUM_VALUE(CV_HLSLREG_IMMEDIATE64, 5) \
    ENUM_VALUE(CV_HLSLREG_SAMPLER, 6) \
    ENUM_VALUE(CV_HLSLREG_RESOURCE, 7) \
    ENUM_VALUE(CV_HLSLREG_CONSTANT_BUFFER, 8) \
    ENUM_VALUE(CV_HLSLREG_IMMEDIATE_CONSTANT_BUFFER, 9) \
    ENUM_VALUE(CV_HLSLREG_LABEL, 10) \
    ENUM_VALUE(CV_HLSLREG_INPUT_PRIMITIVEID, 11) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT_DEPTH, 12) \
    ENUM_VALUE(CV_HLSLREG_NULL, 13) \
    ENUM_VALUE(CV_HLSLREG_RASTERIZER, 14) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT_COVERAGE_MASK, 15) \
    ENUM_VALUE(CV_HLSLREG_STREAM, 16) \
    ENUM_VALUE(CV_HLSLREG_FUNCTION_BODY, 17) \
    ENUM_VALUE(CV_HLSLREG_FUNCTION_TABLE, 18) \
    ENUM_VALUE(CV_HLSLREG_INTERFACE, 19) \
    ENUM_VALUE(CV_HLSLREG_FUNCTION_INPUT, 20) \
    ENUM_VALUE(CV_HLSLREG_FUNCTION_OUTPUT, 21) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT_CONTROL_POINT_ID, 22) \
    ENUM_VALUE(CV_HLSLREG_INPUT_FORK_INSTANCE_ID, 23) \
    ENUM_VALUE(CV_HLSLREG_INPUT_JOIN_INSTANCE_ID, 24) \
    ENUM_VALUE(CV_HLSLREG_INPUT_CONTROL_POINT, 25) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT_CONTROL_POINT, 26) \
    ENUM_VALUE(CV_HLSLREG_INPUT_PATCH_CONSTANT, 27) \
    ENUM_VALUE(CV_HLSLREG_INPUT_DOMAIN_POINT, 28) \
    ENUM_VALUE(CV_HLSLREG_THIS_POINTER, 29) \
    ENUM_VALUE(CV_HLSLREG_UNORDERED_ACCESS_VIEW, 30) \
    ENUM_VALUE(CV_HLSLREG_THREAD_GROUP_SHARED_MEMORY, 31) \
    ENUM_VALUE(CV_HLSLREG_INPUT_THREAD_ID, 32) \
    ENUM_VALUE(CV_HLSLREG_INPUT_THREAD_GROUP_ID, 33) \
    ENUM_VALUE(CV_HLSLREG_INPUT_THREAD_ID_IN_GROUP, 34) \
    ENUM_VALUE(CV_HLSLREG_INPUT_COVERAGE_MASK, 35) \
    ENUM_VALUE(CV_HLSLREG_INPUT_THREAD_ID_IN_GROUP_FLATTENED, 36) \
    ENUM_VALUE(CV_HLSLREG_INPUT_GS_INSTANCE_ID, 37) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT_DEPTH_GREATER_EQUAL, 38) \
    ENUM_VALUE(CV_HLSLREG_OUTPUT_DEPTH_LESS_EQUAL, 39) \
    ENUM_VALUE(CV_HLSLREG_CYCLE_COUNTER, 40) \
ENUM_END(cv_hlsl_register_type)

CV_HLSL_REGISTER_TYPE_ENUM

void cv_hlsl_register_type_print(enum cv_hlsl_register_type item, FILE *stream);

/* ---------- CV def range hlsl packed data */

#define CV_DEF_RANGE_HLSL_PACKED_DATA_STRUCT \
STRUCT_DECL(cv_def_range_hlsl_packed_data) \
    FIELD_PRIMITIVE_BITS(uint16_t, register_index_count, 2, "%u") /* 0, 1 or 2, dimensionality of register space */ \
    FIELD_PRIMITIVE_BITS(uint16_t, spilled_udt_member, 1, "%u") /* this is a spilled member */ \
    FIELD_PRIMITIVE_BITS(uint16_t, memory_space, 4, "%u") /* memory space */ \
    FIELD_PRIMITIVE_BITS(uint16_t, padding, 9, "%u") /* for future use */ \
STRUCT_END(cv_def_range_hlsl_packed_data)

CV_DEF_RANGE_HLSL_PACKED_DATA_STRUCT
static_assert(sizeof(struct cv_def_range_hlsl_packed_data) == sizeof(uint16_t), "invalid cv_def_range_hlsl_packed_data size");

void cv_def_range_hlsl_packed_data_print(struct cv_def_range_hlsl_packed_data *item, uint32_t depth, FILE *stream);

/* ---------- CV def range hlsl symbol */

#define CV_DEF_RANGE_HLSL_SYMBOL_STRUCT \
STRUCT_DECL(cv_def_range_hlsl_symbol) \
    FIELD_PRIMITIVE_FMT(uint16_t, register_type, cv_hlsl_register_type_print) \
    FIELD_STRUCT(struct cv_def_range_hlsl_packed_data, packed_data, cv_def_range_hlsl_packed_data_print) \
    FIELD_PRIMITIVE(uint16_t, parent_offset, "%u") \
    FIELD_PRIMITIVE(uint16_t, parent_size, "%u") \
    FIELD_STRUCT(struct cv_address_range, range, cv_address_range_print) \
    FIELD_PRIMITIVE(uint32_t, gap_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_address_gap *, gaps, gap_count, cv_address_gap_print) \
    FIELD_PRIMITIVE_DYNAMIC_ARRAY(uint32_t *, register_indices, packed_data.register_index_count, "%u") \
STRUCT_END(cv_def_range_hlsl_symbol)

CV_DEF_RANGE_HLSL_SYMBOL_STRUCT

void cv_def_range_hlsl_symbol_dispose(struct cv_def_range_hlsl_symbol *item);
void cv_def_range_hlsl_symbol_print(struct cv_def_range_hlsl_symbol *item, uint32_t depth, FILE *stream);
void cv_def_range_hlsl_symbol_read(struct cv_def_range_hlsl_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV local dpc group shared symbol */

#define CV_LOCAL_DPC_GROUP_SHARED_SYMBOL_STRUCT \
STRUCT_DECL(cv_local_dpc_group_shared_symbol) \
    FIELD_PRIMITIVE(uint32_t, type_index, "%u") \
    FIELD_STRUCT(struct cv_local_variable_flags, flags, cv_local_variable_flags_print) \
    FIELD_PRIMITIVE(uint16_t, data_slot, "%u") \
    FIELD_PRIMITIVE(uint16_t, data_offset, "%u") \
    FIELD_PRIMITIVE(char *, name, "\"%s\"") \
STRUCT_END(cv_local_dpc_group_shared_symbol)

CV_LOCAL_DPC_GROUP_SHARED_SYMBOL_STRUCT

void cv_local_dpc_group_shared_symbol_dispose(struct cv_local_dpc_group_shared_symbol *item);
void cv_local_dpc_group_shared_symbol_print(struct cv_local_dpc_group_shared_symbol *item, uint32_t depth, FILE *stream);
void cv_local_dpc_group_shared_symbol_read(struct cv_local_dpc_group_shared_symbol *item, uint16_t symbol_type, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV dpc symbol tag map entry */

#define CV_DPC_SYMBOL_TAG_MAP_ENTRY_STRUCT \
STRUCT_DECL(cv_dpc_symbol_tag_map_entry) \
    FIELD_PRIMITIVE(uint32_t, tag_value, "%u") /* address taken symbol's pointer tag value. */ \
    FIELD_PRIMITIVE(int32_t, symbol_record_offset, "%u") /* offset of the symbol record from the S_LPROC32_DPC record it is nested within */ \
STRUCT_END(cv_dpc_symbol_tag_map_entry)

CV_DPC_SYMBOL_TAG_MAP_ENTRY_STRUCT
static_assert(sizeof(struct cv_dpc_symbol_tag_map_entry) == 8, "invalid cv_dpc_symbol_tag_map_entry size");

void cv_dpc_symbol_tag_map_entry_print(struct cv_dpc_symbol_tag_map_entry *item, uint32_t depth, FILE *stream);

/* ---------- CV dpc symbol tag map symbol */

#define CV_DPC_SYMBOL_TAG_MAP_SYMBOL_STRUCT \
STRUCT_DECL(cv_dpc_symbol_tag_map_symbol) \
    FIELD_PRIMITIVE(uint32_t, entry_count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_dpc_symbol_tag_map_entry *, entries, entry_count, cv_dpc_symbol_tag_map_entry_print) \
STRUCT_END(cv_dpc_symbol_tag_map_symbol)

CV_DPC_SYMBOL_TAG_MAP_SYMBOL_STRUCT

void cv_dpc_symbol_tag_map_symbol_dispose(struct cv_dpc_symbol_tag_map_symbol *item);
void cv_dpc_symbol_tag_map_symbol_print(struct cv_dpc_symbol_tag_map_symbol *item, uint32_t depth, FILE *stream);
void cv_dpc_symbol_tag_map_symbol_read(struct cv_dpc_symbol_tag_map_symbol *item, uint32_t symbol_size, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV function list symbol */

#define CV_FUNCTION_LIST_SYMBOL_STRUCT \
STRUCT_DECL(cv_function_list_symbol) \
    FIELD_PRIMITIVE(uint32_t, count, "%u") \
    FIELD_PRIMITIVE_DYNAMIC_ARRAY(uint32_t *, type_indices, count, "%u") \
STRUCT_END(cv_function_list_symbol)

CV_FUNCTION_LIST_SYMBOL_STRUCT

void cv_function_list_symbol_dispose(struct cv_function_list_symbol *item);
void cv_function_list_symbol_print(struct cv_function_list_symbol *item, uint32_t depth, FILE *stream);
void cv_function_list_symbol_read(struct cv_function_list_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV pogo data symbol */

#define CV_POGO_DATA_SYMBOL_STRUCT \
STRUCT_DECL(cv_pogo_data_symbol) \
    FIELD_PRIMITIVE(uint32_t, invocations, "%u") /* Number of times function was called */ \
    FIELD_PRIMITIVE(int64_t, dynamic_instruction_count, "%lli") /* Dynamic instruction count */ \
    FIELD_PRIMITIVE(uint32_t, static_instruction_count, "%u") /* Static instruction count */ \
    FIELD_PRIMITIVE(uint32_t, final_static_instruction_count, "%u") /* Final static instruction count (post inlining) */ \
STRUCT_END(cv_pogo_data_symbol)

CV_POGO_DATA_SYMBOL_STRUCT

void cv_pogo_data_symbol_print(struct cv_pogo_data_symbol *item, uint32_t depth, FILE *stream);
void cv_pogo_data_symbol_read(struct cv_pogo_data_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV arm switch table symbol */

#define CV_ARM_SWITCH_TABLE_SYMBOL_STRUCT \
STRUCT_DECL(cv_arm_switch_table_symbol) \
    FIELD_PRIMITIVE(uint32_t, offset_base, "%u") /* Section-relative offset to the base for switch offsets */ \
    FIELD_PRIMITIVE(uint16_t, sect_base, "%u") /* Section index of the base for switch offsets */ \
    FIELD_PRIMITIVE(uint16_t, switch_type, "%u") /* type of each entry */ \
    FIELD_PRIMITIVE(uint32_t, offset_branch, "%u") /* Section-relative offset to the table branch instruction */ \
    FIELD_PRIMITIVE(uint32_t, offset_table, "%u") /* Section-relative offset to the start of the table */ \
    FIELD_PRIMITIVE(uint16_t, sect_branch, "%u") /* Section index of the table branch instruction */ \
    FIELD_PRIMITIVE(uint16_t, sect_table, "%u") /* Section index of the table */ \
    FIELD_PRIMITIVE(uint32_t, c_entries, "%u") /* number of switch table entries */ \
STRUCT_END(cv_arm_switch_table_symbol)

CV_ARM_SWITCH_TABLE_SYMBOL_STRUCT
static_assert(sizeof(struct cv_arm_switch_table_symbol) == 24, "invalid cv_arm_switch_table_symbol size");

void cv_arm_switch_table_symbol_print(struct cv_arm_switch_table_symbol *item, uint32_t depth, FILE *stream);
void cv_arm_switch_table_symbol_read(struct cv_arm_switch_table_symbol *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t *out_offset, struct memory_stream *file_stream);

/* ---------- CV symbol */

#define CV_SYMBOL_STRUCT \
STRUCT_DECL(cv_symbol) \
    FIELD_PRIMITIVE_FMT(uint16_t, type, cv_symbol_type_print) \
    FIELD_PRIMITIVE(uint16_t, size, "%u") \
    FIELD_UNION_DECL() \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_obj_name_symbol, obj_name, type, cv_obj_name_symbol_print, S_OBJNAME, S_OBJNAME_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_register_variable_symbol, register_variable, type, cv_register_variable_symbol_print, S_REGISTER, S_REGISTER_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_constant_symbol, constant, type, cv_constant_symbol_print, S_CONSTANT, S_CONSTANT_ST, S_MANCONSTANT) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_user_defined_type_symbol, user_defined_type, type, cv_user_defined_type_symbol_print, S_UDT, S_UDT_ST, S_COBOLUDT, S_COBOLUDT_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_multi_register_variable_symbol, multi_register_variable, type, cv_multi_register_variable_symbol_print, S_MANYREG, S_MANYREG_ST, S_MANYREG2, S_MANYREG2_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_data_symbol, data, type, cv_data_symbol_print, S_LDATA32, S_LDATA32_ST, S_GDATA32, S_GDATA32_ST, S_LMANDATA, S_LMANDATA_ST, S_GMANDATA, S_GMANDATA_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_public_symbol, public_, type, cv_public_symbol_print, S_PUB32, S_PUB32_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_procedure_symbol, procedure, type, cv_procedure_symbol_print, S_LPROC32, S_LPROC32_ST, S_GPROC32, S_GPROC32_ST, S_LPROC32_ID, S_GPROC32_ID, S_LPROC32_DPC, S_LPROC32_DPC_ID) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_thread_storage_symbol, thread_storage, type, cv_thread_storage_symbol_print, S_LTHREAD32, S_LTHREAD32_ST, S_GTHREAD32, S_GTHREAD32_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_compile_flags_symbol, compile_flags, type, cv_compile_flags_symbol_print, S_COMPILE2, S_COMPILE2_ST, S_COMPILE3) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_using_namespace_symbol, using_namespace, type, cv_using_namespace_symbol_print, S_UNAMESPACE, S_UNAMESPACE_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_procedure_reference_symbol, procedure_reference, type, cv_procedure_reference_symbol_print, S_PROCREF, S_PROCREF_ST, S_LPROCREF, S_LPROCREF_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_data_reference_symbol, data_reference, type, cv_data_reference_symbol_print, S_DATAREF, S_DATAREF_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_annotation_reference_symbol, annotation_reference, type, cv_annotation_reference_symbol_print, S_ANNOTATIONREF) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_trampoline_symbol, trampoline, type, cv_trampoline_symbol_print, S_TRAMPOLINE) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_export_symbol, export, type, cv_export_symbol_print, S_EXPORT) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_local_symbol, local, type, cv_local_symbol_print, S_LOCAL) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_build_info_symbol, build_info, type, cv_build_info_symbol_print, S_BUILDINFO) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_inline_site_symbol, inline_site, type, cv_inline_site_symbol_print, S_INLINESITE, S_INLINESITE2) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_label_symbol, label, type, cv_label_symbol_print, S_LABEL32, S_LABEL32_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_block_symbol, block, type, cv_block_symbol_print, S_BLOCK32, S_BLOCK32_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_register_relative_symbol, register_relative, type, cv_register_relative_symbol_print, S_REGREL32) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_thunk_symbol, thunk, type, cv_thunk_symbol_print, S_THUNK32, S_THUNK32_ST) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_separated_code_symbol, separated_code, type, cv_separated_code_symbol_print, S_SEPCODE) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_frame_cookie_symbol, frame_cookie, type, cv_frame_cookie_symbol_print, S_FRAMECOOKIE) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_frame_proc_symbol, frame_proc, type, cv_frame_proc_symbol_print, S_FRAMEPROC) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_call_site_info_symbol, call_site_info, type, cv_call_site_info_symbol_print, S_CALLSITEINFO) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_heap_alloc_site_symbol, heap_alloc_site, type, cv_heap_alloc_site_symbol_print, S_HEAPALLOCSITE) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_env_block_symbol, env_block, type, cv_env_block_symbol_print, S_ENVBLOCK) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_file_static_symbol, file_static, type, cv_file_static_symbol_print, S_FILESTATIC) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_section_symbol, section, type, cv_section_symbol_print, S_SECTION) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_coff_group_symbol, coff_group, type, cv_coff_group_symbol_print, S_COFFGROUP) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_annotation_symbol, annotation, type, cv_annotation_symbol_print, S_ANNOTATION) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_symbol, def_range, type, cv_def_range_symbol_print, S_DEFRANGE) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_subfield_symbol, def_range_subfield, type, cv_def_range_subfield_symbol_print, S_DEFRANGE_SUBFIELD) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_register_symbol, def_range_register, type, cv_def_range_register_symbol_print, S_DEFRANGE_REGISTER) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_frame_pointer_rel_symbol, def_range_frame_pointer_rel, type, cv_def_range_frame_pointer_rel_symbol_print, S_DEFRANGE_FRAMEPOINTER_REL, S_DEFRANGE_FRAMEPOINTER_REL_FULL_SCOPE) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_subfield_register_symbol, def_range_subfield_register, type, cv_def_range_subfield_register_symbol_print, S_DEFRANGE_SUBFIELD_REGISTER) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_register_rel_symbol, def_range_register_rel, type, cv_def_range_register_rel_symbol_print, S_DEFRANGE_REGISTER_REL) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_def_range_hlsl_symbol, def_range_hlsl, type, cv_def_range_hlsl_symbol_print, S_DEFRANGE_HLSL, S_DEFRANGE_DPC_PTR_TAG) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_local_dpc_group_shared_symbol, local_dpc_group_shared, type, cv_local_dpc_group_shared_symbol_print, S_LOCAL_DPC_GROUPSHARED) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_dpc_symbol_tag_map_symbol, dpc_symbol_tag_map, type, cv_dpc_symbol_tag_map_symbol_print, S_DPC_SYM_TAG_MAP) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_function_list_symbol, function_list, type, cv_function_list_symbol_print, S_CALLERS, S_CALLEES, S_INLINEES) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_pogo_data_symbol, pogo_data, type, cv_pogo_data_symbol_print, S_POGODATA) \
        FIELD_UNION_FIELD_STRUCT_MULTITAG(struct cv_arm_switch_table_symbol, arm_switch_table, type, cv_arm_switch_table_symbol_print, S_ARMSWITCHTABLE) \
    FIELD_UNION_END() \
STRUCT_END(cv_symbol)

CV_SYMBOL_STRUCT

void cv_symbol_dispose(struct cv_symbol *item);
void cv_symbol_print(struct cv_symbol *item, uint32_t depth, FILE *stream);

/* ---------- CV symbols */

#define CV_SYMBOLS_STRUCT \
STRUCT_DECL(cv_symbols) \
    FIELD_PRIMITIVE(uint32_t, count, "%u") \
    FIELD_STRUCT_DYNAMIC_ARRAY(struct cv_symbol *, symbols, count, cv_symbol_print) \
STRUCT_END(cv_symbols)

CV_SYMBOLS_STRUCT

void cv_symbols_dispose(struct cv_symbols *item);
void cv_symbols_print(struct cv_symbols *item, uint32_t depth, FILE *stream);
void cv_symbols_read(struct cv_symbols *item, struct msf *msf, struct msf_stream *msf_stream, uint32_t size, uint32_t *out_offset, struct memory_stream *file_stream);
