
//  Microsoft (R) .NET Framework IL Disassembler.  Version 4.8.3928.0
//  Copyright (c) Microsoft Corporation.  All rights reserved.


// ----- DOS Header:
// Magic:                      0x5a4d
// Bytes on last page:         0x0090
// Pages in file:              0x0003
// Relocations:                0x0000
// Size of header (paragraphs):0x0004
// Min extra paragraphs:       0x0000
// Max extra paragraphs:       0xffff
// Initial (relative) SS:      0x0000
// Initial SP:                 0x00b8
// Checksum:                   0x0000
// Initial IP:                 0x0000
// Initial (relative) CS:      0x0000
// File addr. of reloc table:  0x0040
// Overlay number:             0x0000
// OEM identifier:             0x0000
// OEM info:                   0x0000
// File addr. of COFF header:  0x0080
// ----- COFF/PE Headers:
// Signature:                  0x00004550
// ----- COFF Header:
// Machine:                    0x014c
// Number of sections:         0x0003
// Time-date stamp:            0x61783a01
// Ptr to symbol table:        0x00000000
// Number of symbols:          0x00000000
// Size of optional header:    0x00e0
// Characteristics:            0x2102
// ----- PE Optional Header (32 bit):
// Magic:                          0x010b
// Major linker version:           0x0b
// Minor linker version:           0x00
// Size of code:                   0x00000800
// Size of init.data:              0x00000600
// Size of uninit.data:            0x00000000
// Addr. of entry point:           0x0000266e
// Base of code:                   0x00002000
// Base of data:                   0x00004000
// Image base:                     0x00400000
// Section alignment:              0x00002000
// File alignment:                 0x00000200
// Major OS version:               0x0004
// Minor OS version:               0x0000
// Major image version:            0x0000
// Minor image version:            0x0000
// Major subsystem version:        0x0004
// Minor subsystem version:        0x0000
// Size of image:                  0x00008000
// Size of headers:                0x00000200
// Checksum:                       0x00000000
// Subsystem:                      0x0003
// DLL characteristics:            0x8540
// Size of stack reserve:          0x00100000
// Size of stack commit:           0x00001000
// Size of heap reserve:           0x00100000
// Size of heap commit:            0x00001000
// Loader flags:                   0x00000000
// Directories:                    0x00000010
// 0x00000000 [0x00000000] address [size] of Export Directory:          
// 0x00002620 [0x0000004b] address [size] of Import Directory:          
// 0x00004000 [0x00000350] address [size] of Resource Directory:        
// 0x00000000 [0x00000000] address [size] of Exception Directory:       
// 0x00000000 [0x00000000] address [size] of Security Directory:        
// 0x00006000 [0x0000000c] address [size] of Base Relocation Table:     
// 0x00000000 [0x00000000] address [size] of Debug Directory:           
// 0x00000000 [0x00000000] address [size] of Architecture Specific:     
// 0x00000000 [0x00000000] address [size] of Global Pointer:            
// 0x00000000 [0x00000000] address [size] of TLS Directory:             
// 0x00000000 [0x00000000] address [size] of Load Config Directory:     
// 0x00000000 [0x00000000] address [size] of Bound Import Directory:    
// 0x00002000 [0x00000008] address [size] of Import Address Table:      
// 0x00000000 [0x00000000] address [size] of Delay Load IAT:            
// 0x00002008 [0x00000048] address [size] of CLR Header:                


// Image sections:
//              .text
//              0x00000674 Virtual Size
//              0x00002000 Virtual Address
//              0x00000800 Size of Raw Data
//              0x00000200 Pointer to Raw Data
//              0x00000000 Pointer to Relocations
//              0x00000000 Pointer to Linenumbers
//                  0x0000 Number of Relocations
//                  0x0000 Number of Linenumbers
//              0x60000020 Characteristics
//                         CNT_CODE
//                         MEM_EXECUTE
//                         MEM_READ

//              .rsrc
//              0x00000350 Virtual Size
//              0x00004000 Virtual Address
//              0x00000400 Size of Raw Data
//              0x00000a00 Pointer to Raw Data
//              0x00000000 Pointer to Relocations
//              0x00000000 Pointer to Linenumbers
//                  0x0000 Number of Relocations
//                  0x0000 Number of Linenumbers
//              0x40000040 Characteristics
//                         CNT_INITIALIZED_DATA
//                         MEM_READ

//              .reloc
//              0x0000000c Virtual Size
//              0x00006000 Virtual Address
//              0x00000200 Size of Raw Data
//              0x00000e00 Pointer to Raw Data
//              0x00000000 Pointer to Relocations
//              0x00000000 Pointer to Linenumbers
//                  0x0000 Number of Relocations
//                  0x0000 Number of Linenumbers
//              0x42000040 Characteristics
//                         CNT_INITIALIZED_DATA
//                         MEM_DISCARDABLE
//                         MEM_READ

// Base Relocation Table
//              0x00002000 Page RVA
//              0x0000000c Block Size
//              0x00000002 Number of Entries
//              Entry 1: Type 0x3 Offset 0x00000670
//              Entry 2: Type 0x0 Offset 0x00000000

// Import Address Table
//     DLL : mscoree.dll
//              0x00002000 Import Address Table
//              0x0000265e Import Name Table
//              0          Time Date Stamp
//              0          Index of First Forwarder Reference
//
//              0x0000  _CorDllMain

// Delay Load Import Address Table
// No data.

// Entry point code:
//FF 25 00 20 40 00 


// ----- CLR Header:
// Header size:                        0x00000048
// Major runtime version:              0x0002
// Minor runtime version:              0x0005
// 0x00002050 [0x000005d0] address [size] of Metadata Directory:        
// Flags:                              0x00000001
// Entry point token:                  0x00000000
// 0x00000000 [0x00000000] address [size] of Resources Directory:       
// 0x00000000 [0x00000000] address [size] of Strong Name Signature:     
// 0x00000000 [0x00000000] address [size] of CodeManager Table:         
// 0x00000000 [0x00000000] address [size] of VTableFixups Directory:    
// 0x00000000 [0x00000000] address [size] of Export Address Table:      
// 0x00000000 [0x00000000] address [size] of Precompile Header:         

// Metadata Header
//    Storage Signature:
//              0x424a5342 Signature
//                  0x0001 Major Version
//                  0x0001 Minor Version
//              0x00000000 Extra Data Offset
//              0x0000000c Version String Length
//              'v4.0.30319' Version String
//    Storage Header:
//                    0x00 Flags
//                  0x0005 Number of Streams
//    Stream 1:
//              0x0000006c Offset
//              0x00000220 Size
//              '#~' Name
//    Stream 2:
//              0x0000028c Offset
//              0x000001e0 Size
//              '#Strings' Name
//    Stream 3:
//              0x0000046c Offset
//              0x00000008 Size
//              '#US' Name
//    Stream 4:
//              0x00000474 Offset
//              0x00000010 Size
//              '#GUID' Name
//    Stream 5:
//              0x00000484 Offset
//              0x0000014c Size
//              '#Blob' Name

//    Metadata Stream Header:
//              0x00000000 Reserved
//                    0x02 Major
//                    0x00 Minor
//                    0x00 Heaps
//                    0x10 Rid
//      0x0000000902001747 MaskValid
//      0x000016003325fa00 Sorted

// Code Manager Table:
//  default


// Export Address Table Jumps:
// No data.

// File size            : 4096
// PE header size       : 512 (496 used)    (12.50%)
// PE additional info   : 1015              (24.78%)
// Num.of PE sections   : 3
// CLR header size     : 72                 ( 1.76%)
// CLR meta-data size  : 1488               (36.33%)
// CLR additional info : 0                  ( 0.00%)
// CLR method headers  : 0                  ( 0.00%)
// Managed code         : 0                 ( 0.00%)
// Data                 : 1536              (37.50%)
// Unaccounted          : -527              (-12.87%)

// Num.of PE sections   : 3
//   .text    - 2048
//   .rsrc    - 1024
//   .reloc   - 512

// CLR meta-data size  : 1488
//   Module        -    1 (10 bytes)
//   TypeDef       -    4 (56 bytes)      2 interfaces, 0 explicit layout
//   TypeRef       -   11 (66 bytes)
//   MethodDef     -    5 (70 bytes)      2 abstract, 0 native, 0 bodies
//   MemberRef     -    8 (48 bytes)
//   ParamDef      -   12 (72 bytes)
//   MethodImpl    -    2 (12 bytes)
//   CustomAttribute-   14 (84 bytes)
//   InterfaceImpl -    3 (12 bytes)
//   Assembly      -    1 (22 bytes)
//   AssemblyRef   -    1 (20 bytes)
//   Strings       -   477 bytes
//   Blobs         -   332 bytes
//   UserStrings   -     8 bytes
//   Guids         -    16 bytes
//   Uncategorized -   183 bytes

// CLR method headers : 0
//   Num.of method bodies  - 0
//   Num.of fat headers    - 0
//   Num.of tiny headers   - 0

// Managed code : 0
// Classes defined in this module:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Interface IMyMath                        (public) (abstract) (auto) (ansi) (import) 
// Interface CMyMath                        (public) (abstract) (auto) (ansi) (import) 
// Class CMyMathClass                   (public) (auto) (ansi) (import) 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ================================= M E T A I N F O ================================================

// ===========================================================
// Name,Size,cRecs,cbRec
// Strings,477
// Blobs,332
// Guids,16
// Module,10,1,10
// TypeRef,66,11,6
// TypeDef,56,4,14
// FieldPtr,0,0,2
// Field,0,0,6
// MethodPtr,0,0,2
// Method,70,5,14
// ParamPtr,0,0,2
// Param,72,12,6
// InterfaceImpl,12,3,4
// MemberRef,48,8,6
// Constant,0,0,6
// CustomAttribute,84,14,6
// FieldMarshal,0,0,4
// DeclSecurity,0,0,6
// ClassLayout,0,0,8
// FieldLayout,0,0,6
// StandAloneSig,0,0,2
// EventMap,0,0,4
// EventPtr,0,0,2
// Event,0,0,6
// PropertyMap,0,0,4
// PropertyPtr,0,0,2
// Property,0,0,6
// MethodSemantics,0,0,6
// MethodImpl,12,2,6
// ModuleRef,0,0,2
// TypeSpec,0,0,2
// ImplMap,0,0,8
// FieldRVA,0,0,6
// ENCLog,0,0,8
// ENCMap,0,0,4
// Assembly,22,1,22
// AssemblyProcessor,0,0,4
// AssemblyOS,0,0,12
// AssemblyRef,20,1,20
// AssemblyRefProcessor,0,0,6
// AssemblyRefOS,0,0,14
// File,0,0,8
// ExportedType,0,0,14
// ManifestResource,0,0,12
// NestedClass,0,0,4
// GenericParam,0,0,8
// MethodSpec,0,0,4
// GenericParamConstraint,0,0,4
// Metadata section: 0x424a5342, version: 1.1, extra: 0, version len: 12, version: v4.0.30319
//            flags: 0x00, streams: 5
//         : 42 53 4a 42 01 00 01 00  00 00 00 00 0c 00 00 00 >BSJB            <
//         : 76 34 2e 30 2e 33 30 33  31 39 00 00 00 00 05 00 >v4.0.30319      <
//         : 6c 00 00 00 20 02 00 00  23 7e 00 00 8c 02 00 00 >l       #~      <
//         : e0 01 00 00 23 53 74 72  69 6e 67 73 00 00 00 00 >    #Strings    <
//         : 6c 04 00 00 08 00 00 00  23 55 53 00 74 04 00 00 >l       #US t   <
//         : 10 00 00 00 23 47 55 49  44 00 00 00 84 04 00 00 >    #GUID       <
//         : 4c 01 00 00 23 42 6c 6f  62 00 00 00             >L   #Blob       <
// Stream 0: name: #~, size 544
// Stream 1: name: #Strings, size 480
// Stream 2: name: #US, size 8
// Stream 3: name: #GUID, size 16
// Stream 4: name: #Blob, size 332
// Metadata header: 2.0, heaps: 0x00, rid: 0x10, valid: 0x0000000902001747, sorted: 0x000016003325fa00
//         : 00 00 00 00 02 00 00 10  47 17 00 02 09 00 00 00 >        G       <
//         : 00 fa 25 33 00 16 00 00                          >  %3            <
// 
// Strings: 477(0x1dd), Blobs: 332(0x14c), Guids: 16(0x10), User strings: 8(0x8)
//  0(0): Module               cRecs:    1(0x1), cbRec: 10(0xa), cbTable:    10(0xa)
//   col  0:  Generation   oCol: 0, cbCol:2, USHORT 
//   col  1:  Name         oCol: 2, cbCol:2, string 
//   col  2:  Mvid         oCol: 4, cbCol:2, GUID   
//   col  3:  EncId        oCol: 6, cbCol:2, GUID   
//   col  4:  EncBaseId    oCol: 8, cbCol:2, GUID   
//  1(0x1): TypeRef              cRecs:   11(0xb), cbRec:  6(0x6), cbTable:    66(0x42)
//   col  0:  ResolutionScope oCol: 0, cbCol:2, ResolutionScope
//   col  1:  Name         oCol: 2, cbCol:2, string 
//   col  2:  Namespace    oCol: 4, cbCol:2, string 
//  2(0x2): TypeDef              cRecs:    4(0x4), cbRec: 14(0xe), cbTable:    56(0x38)
//   col  0:  Flags        oCol: 0, cbCol:4, ULONG  
//   col  1:  Name         oCol: 4, cbCol:2, string 
//   col  2:  Namespace    oCol: 6, cbCol:2, string 
//   col  3:  Extends      oCol: 8, cbCol:2, TypeDefOrRef
//   col  4:  FieldList    oCol: a, cbCol:2, Field  
//   col  5:  MethodList   oCol: c, cbCol:2, Method 
//  3(0x3): FieldPtr             cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Field        oCol: 0, cbCol:2, Field  
//  4(0x4): Field                cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  Flags        oCol: 0, cbCol:2, USHORT 
//   col  1:  Name         oCol: 2, cbCol:2, string 
//   col  2:  Signature    oCol: 4, cbCol:2, blob   
//  5(0x5): MethodPtr            cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Method       oCol: 0, cbCol:2, Method 
//  6(0x6): Method               cRecs:    5(0x5), cbRec: 14(0xe), cbTable:    70(0x46)
//   col  0:  RVA          oCol: 0, cbCol:4, ULONG  
//   col  1:  ImplFlags    oCol: 4, cbCol:2, USHORT 
//   col  2:  Flags        oCol: 6, cbCol:2, USHORT 
//   col  3:  Name         oCol: 8, cbCol:2, string 
//   col  4:  Signature    oCol: a, cbCol:2, blob   
//   col  5:  ParamList    oCol: c, cbCol:2, Param  
//  7(0x7): ParamPtr             cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Param        oCol: 0, cbCol:2, Param  
//  8(0x8): Param                cRecs:   12(0xc), cbRec:  6(0x6), cbTable:    72(0x48)
//   col  0:  Flags        oCol: 0, cbCol:2, USHORT 
//   col  1:  Sequence     oCol: 2, cbCol:2, USHORT 
//   col  2:  Name         oCol: 4, cbCol:2, string 
//  9(0x9): InterfaceImpl        cRecs:    3(0x3), cbRec:  4(0x4), cbTable:    12(0xc)
//   col  0:* Class        oCol: 0, cbCol:2, TypeDef
//   col  1:  Interface    oCol: 2, cbCol:2, TypeDefOrRef
// 10(0xa): MemberRef            cRecs:    8(0x8), cbRec:  6(0x6), cbTable:    48(0x30)
//   col  0:  Class        oCol: 0, cbCol:2, MemberRefParent
//   col  1:  Name         oCol: 2, cbCol:2, string 
//   col  2:  Signature    oCol: 4, cbCol:2, blob   
// 11(0xb): Constant             cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  Type         oCol: 0, cbCol:1, BYTE   
//   col  1:* Parent       oCol: 2, cbCol:2, HasConstant
//   col  2:  Value        oCol: 4, cbCol:2, blob   
// 12(0xc): CustomAttribute      cRecs:   14(0xe), cbRec:  6(0x6), cbTable:    84(0x54)
//   col  0:* Parent       oCol: 0, cbCol:2, HasCustomAttribute
//   col  1:  Type         oCol: 2, cbCol:2, CustomAttributeType
//   col  2:  Value        oCol: 4, cbCol:2, blob   
// 13(0xd): FieldMarshal         cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:* Parent       oCol: 0, cbCol:2, HasFieldMarshal
//   col  1:  NativeType   oCol: 2, cbCol:2, blob   
// 14(0xe): DeclSecurity         cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  Action       oCol: 0, cbCol:2, short  
//   col  1:* Parent       oCol: 2, cbCol:2, HasDeclSecurity
//   col  2:  PermissionSet oCol: 4, cbCol:2, blob   
// 15(0xf): ClassLayout          cRecs:    0(0), cbRec:  8(0x8), cbTable:     0(0)
//   col  0:  PackingSize  oCol: 0, cbCol:2, USHORT 
//   col  1:  ClassSize    oCol: 2, cbCol:4, ULONG  
//   col  2:* Parent       oCol: 6, cbCol:2, TypeDef
// 16(0x10): FieldLayout          cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  OffSet       oCol: 0, cbCol:4, ULONG  
//   col  1:* Field        oCol: 4, cbCol:2, Field  
// 17(0x11): StandAloneSig        cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Signature    oCol: 0, cbCol:2, blob   
// 18(0x12): EventMap             cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:  Parent       oCol: 0, cbCol:2, TypeDef
//   col  1:  EventList    oCol: 2, cbCol:2, Event  
// 19(0x13): EventPtr             cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Event        oCol: 0, cbCol:2, Event  
// 20(0x14): Event                cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  EventFlags   oCol: 0, cbCol:2, USHORT 
//   col  1:  Name         oCol: 2, cbCol:2, string 
//   col  2:  EventType    oCol: 4, cbCol:2, TypeDefOrRef
// 21(0x15): PropertyMap          cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:  Parent       oCol: 0, cbCol:2, TypeDef
//   col  1:  PropertyList oCol: 2, cbCol:2, Property
// 22(0x16): PropertyPtr          cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Property     oCol: 0, cbCol:2, Property
// 23(0x17): Property             cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  PropFlags    oCol: 0, cbCol:2, USHORT 
//   col  1:  Name         oCol: 2, cbCol:2, string 
//   col  2:  Type         oCol: 4, cbCol:2, blob   
// 24(0x18): MethodSemantics      cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  Semantic     oCol: 0, cbCol:2, USHORT 
//   col  1:  Method       oCol: 2, cbCol:2, Method 
//   col  2:* Association  oCol: 4, cbCol:2, HasSemantic
// 25(0x19): MethodImpl           cRecs:    2(0x2), cbRec:  6(0x6), cbTable:    12(0xc)
//   col  0:* Class        oCol: 0, cbCol:2, TypeDef
//   col  1:  MethodBody   oCol: 2, cbCol:2, MethodDefOrRef
//   col  2:  MethodDeclaration oCol: 4, cbCol:2, MethodDefOrRef
// 26(0x1a): ModuleRef            cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Name         oCol: 0, cbCol:2, string 
// 27(0x1b): TypeSpec             cRecs:    0(0), cbRec:  2(0x2), cbTable:     0(0)
//   col  0:  Signature    oCol: 0, cbCol:2, blob   
// 28(0x1c): ImplMap              cRecs:    0(0), cbRec:  8(0x8), cbTable:     0(0)
//   col  0:  MappingFlags oCol: 0, cbCol:2, USHORT 
//   col  1:* MemberForwarded oCol: 2, cbCol:2, MemberForwarded
//   col  2:  ImportName   oCol: 4, cbCol:2, string 
//   col  3:  ImportScope  oCol: 6, cbCol:2, ModuleRef
// 29(0x1d): FieldRVA             cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  RVA          oCol: 0, cbCol:4, ULONG  
//   col  1:* Field        oCol: 4, cbCol:2, Field  
// 30(0x1e): ENCLog               cRecs:    0(0), cbRec:  8(0x8), cbTable:     0(0)
//   col  0:  Token        oCol: 0, cbCol:4, ULONG  
//   col  1:  FuncCode     oCol: 4, cbCol:4, ULONG  
// 31(0x1f): ENCMap               cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:  Token        oCol: 0, cbCol:4, ULONG  
// 32(0x20): Assembly             cRecs:    1(0x1), cbRec: 22(0x16), cbTable:    22(0x16)
//   col  0:  HashAlgId    oCol: 0, cbCol:4, ULONG  
//   col  1:  MajorVersion oCol: 4, cbCol:2, USHORT 
//   col  2:  MinorVersion oCol: 6, cbCol:2, USHORT 
//   col  3:  BuildNumber  oCol: 8, cbCol:2, USHORT 
//   col  4:  RevisionNumber oCol: a, cbCol:2, USHORT 
//   col  5:  Flags        oCol: c, cbCol:4, ULONG  
//   col  6:  PublicKey    oCol:10, cbCol:2, blob   
//   col  7:  Name         oCol:12, cbCol:2, string 
//   col  8:  Locale       oCol:14, cbCol:2, string 
// 33(0x21): AssemblyProcessor    cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:  Processor    oCol: 0, cbCol:4, ULONG  
// 34(0x22): AssemblyOS           cRecs:    0(0), cbRec: 12(0xc), cbTable:     0(0)
//   col  0:  OSPlatformId oCol: 0, cbCol:4, ULONG  
//   col  1:  OSMajorVersion oCol: 4, cbCol:4, ULONG  
//   col  2:  OSMinorVersion oCol: 8, cbCol:4, ULONG  
// 35(0x23): AssemblyRef          cRecs:    1(0x1), cbRec: 20(0x14), cbTable:    20(0x14)
//   col  0:  MajorVersion oCol: 0, cbCol:2, USHORT 
//   col  1:  MinorVersion oCol: 2, cbCol:2, USHORT 
//   col  2:  BuildNumber  oCol: 4, cbCol:2, USHORT 
//   col  3:  RevisionNumber oCol: 6, cbCol:2, USHORT 
//   col  4:  Flags        oCol: 8, cbCol:4, ULONG  
//   col  5:  PublicKeyOrToken oCol: c, cbCol:2, blob   
//   col  6:  Name         oCol: e, cbCol:2, string 
//   col  7:  Locale       oCol:10, cbCol:2, string 
//   col  8:  HashValue    oCol:12, cbCol:2, blob   
// 36(0x24): AssemblyRefProcessor cRecs:    0(0), cbRec:  6(0x6), cbTable:     0(0)
//   col  0:  Processor    oCol: 0, cbCol:4, ULONG  
//   col  1:  AssemblyRef  oCol: 4, cbCol:2, AssemblyRef
// 37(0x25): AssemblyRefOS        cRecs:    0(0), cbRec: 14(0xe), cbTable:     0(0)
//   col  0:  OSPlatformId oCol: 0, cbCol:4, ULONG  
//   col  1:  OSMajorVersion oCol: 4, cbCol:4, ULONG  
//   col  2:  OSMinorVersion oCol: 8, cbCol:4, ULONG  
//   col  3:  AssemblyRef  oCol: c, cbCol:2, AssemblyRef
// 38(0x26): File                 cRecs:    0(0), cbRec:  8(0x8), cbTable:     0(0)
//   col  0:  Flags        oCol: 0, cbCol:4, ULONG  
//   col  1:  Name         oCol: 4, cbCol:2, string 
//   col  2:  HashValue    oCol: 6, cbCol:2, blob   
// 39(0x27): ExportedType         cRecs:    0(0), cbRec: 14(0xe), cbTable:     0(0)
//   col  0:  Flags        oCol: 0, cbCol:4, ULONG  
//   col  1:  TypeDefId    oCol: 4, cbCol:4, ULONG  
//   col  2:  TypeName     oCol: 8, cbCol:2, string 
//   col  3:  TypeNamespace oCol: a, cbCol:2, string 
//   col  4:  Implementation oCol: c, cbCol:2, Implementation
// 40(0x28): ManifestResource     cRecs:    0(0), cbRec: 12(0xc), cbTable:     0(0)
//   col  0:  Offset       oCol: 0, cbCol:4, ULONG  
//   col  1:  Flags        oCol: 4, cbCol:4, ULONG  
//   col  2:  Name         oCol: 8, cbCol:2, string 
//   col  3:  Implementation oCol: a, cbCol:2, Implementation
// 41(0x29): NestedClass          cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:* NestedClass  oCol: 0, cbCol:2, TypeDef
//   col  1:  EnclosingClass oCol: 2, cbCol:2, TypeDef
// 42(0x2a): GenericParam         cRecs:    0(0), cbRec:  8(0x8), cbTable:     0(0)
//   col  0:  Number       oCol: 0, cbCol:2, USHORT 
//   col  1:  Flags        oCol: 2, cbCol:2, USHORT 
//   col  2:* Owner        oCol: 4, cbCol:2, TypeOrMethodDef
//   col  3:  Name         oCol: 6, cbCol:2, string 
// 43(0x2b): MethodSpec           cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:  Method       oCol: 0, cbCol:2, MethodDefOrRef
//   col  1:  Instantiation oCol: 2, cbCol:2, blob   
// 44(0x2c): GenericParamConstraint cRecs:    0(0), cbRec:  4(0x4), cbTable:     0(0)
//   col  0:* Owner        oCol: 0, cbCol:2, GenericParam
//   col  1:  Constraint   oCol: 2, cbCol:2, TypeDefOrRef
// 
// Blob Heap:  332(0x14c) bytes
//     0,0 :                                                  >                <
//     1,8 : b7 7a 5c 56 19 34 e0 89                          > z\V 4          <
//     a,5 : 20 02 08 08 08                                   >                <
//    10,3 : 20 00 01                                         >                <
//    14,4 : 20 01 01 0e                                      >                <
//    19,5 : 20 02 01 08 08                                   >                <
//    1f,5 : 20 01 01 11 15                                   >                <
//    25,5 : 20 01 01 11 21                                   >    !           <
//    2b,5 : 20 01 01 12 29                                   >    )           <
//    31,4 : 20 01 01 08                                      >                <
//    36,27: 01 00 22 41 75 74 6f 6d  61 74 69 6f 6e 53 65 72 >  "AutomationSer<
//         : 76 65 72 57 69 74 68 52  65 67 46 69 6c 65 54 79 >verWithRegFileTy<
//         : 70 65 4c 69 62 00 00                             >peLib           <
//    5e,c : 01 00 01 00 00 00 00 00  00 00 00 00             >                <
//    6b,29: 01 00 24 46 31 34 43 38  45 32 30 2d 35 35 42 31 >  $F14C8E20-55B1<
//         : 2d 34 46 33 33 2d 42 35  31 38 2d 42 35 45 33 34 >-4F33-B518-B5E34<
//         : 38 35 33 34 36 39 32 00  00                      >8534692         <
//    95,29: 01 00 24 45 43 34 34 39  43 41 30 2d 42 45 31 41 >  $EC449CA0-BE1A<
//         : 2d 34 35 37 31 2d 38 39  42 37 2d 46 32 45 36 31 >-4571-89B7-F2E61<
//         : 35 33 43 45 32 34 33 00  00                      >53CE243         <
//    bf,8 : 01 00 40 10 00 00 00 00                          >  @             <
//    c8,29: 01 00 24 34 34 45 41 35  30 31 46 2d 35 31 35 45 >  $44EA501F-515E<
//         : 2d 34 42 38 41 2d 38 37  38 36 2d 32 33 38 44 34 >-4B8A-8786-238D4<
//         : 31 31 30 41 33 31 45 00  00                      >110A31E         <
//    f2,8 : 01 00 00 00 00 00 00 00                          >                <
//    fb,8 : 01 00 02 00 00 00 00 00                          >                <
//   104,32: 01 00 2d 41 75 74 6f 6d  61 74 69 6f 6e 53 65 72 >  -AutomationSer<
//         : 76 65 72 54 79 70 65 4c  69 62 46 6f 72 44 6f 74 >verTypeLibForDot<
//         : 4e 65 74 2e 43 4d 79 4d  61 74 68 43 6c 61 73 73 >Net.CMyMathClass<
//         : 00 00                                            >                <
//   137,8 : 01 00 00 00 02 60 00 00                          >     `          <
//   140,8 : 01 00 01 00 02 60 00 00                          >     `          <
//   149,0 :                                                  >                <
//   14a,0 :                                                  >                <
//   14b,0 :                                                  >                <
// 
// String Heap:  477(0x1dd) bytes
// 00000000: 00                                               >                <
// 00000001: 3c 4d 6f 64 75 6c 65 3e  00                      ><Module>        <
// 0000000a: 49 4d 79 4d 61 74 68 00                          >IMyMath         <
// 00000012: 41 75 74 6f 6d 61 74 69  6f 6e 53 65 72 76 65 72 >AutomationServer<
//         : 54 79 70 65 4c 69 62 46  6f 72 44 6f 74 4e 65 74 >TypeLibForDotNet<
//         : 00                                               >                <
// 00000033: 43 4d 79 4d 61 74 68 00                          >CMyMath         <
// 0000003b: 43 4d 79 4d 61 74 68 43  6c 61 73 73 00          >CMyMathClass    <
// 00000048: 6d 73 63 6f 72 6c 69 62  00                      >mscorlib        <
// 00000051: 49 6d 70 6f 72 74 65 64  46 72 6f 6d 54 79 70 65 >ImportedFromType<
//         : 4c 69 62 41 74 74 72 69  62 75 74 65 00          >LibAttribute    <
// 0000006e: 53 79 73 74 65 6d 2e 52  75 6e 74 69 6d 65 2e 49 >System.Runtime.I<
//         : 6e 74 65 72 6f 70 53 65  72 76 69 63 65 73 00    >nteropServices  <
// 0000008d: 54 79 70 65 4c 69 62 56  65 72 73 69 6f 6e 41 74 >TypeLibVersionAt<
//         : 74 72 69 62 75 74 65 00                          >tribute         <
// 000000a5: 47 75 69 64 41 74 74 72  69 62 75 74 65 00       >GuidAttribute   <
// 000000b3: 54 79 70 65 4c 69 62 54  79 70 65 41 74 74 72 69 >TypeLibTypeAttri<
//         : 62 75 74 65 00                                   >bute            <
// 000000c8: 54 79 70 65 4c 69 62 54  79 70 65 46 6c 61 67 73 >TypeLibTypeFlags<
//         : 00                                               >                <
// 000000d9: 4f 62 6a 65 63 74 00                             >Object          <
// 000000e0: 53 79 73 74 65 6d 00                             >System          <
// 000000e7: 43 6c 61 73 73 49 6e 74  65 72 66 61 63 65 41 74 >ClassInterfaceAt<
//         : 74 72 69 62 75 74 65 00                          >tribute         <
// 000000ff: 43 6c 61 73 73 49 6e 74  65 72 66 61 63 65 54 79 >ClassInterfaceTy<
//         : 70 65 00                                         >pe              <
// 00000112: 43 6f 43 6c 61 73 73 41  74 74 72 69 62 75 74 65 >CoClassAttribute<
//         : 00                                               >                <
// 00000123: 54 79 70 65 00                                   >Type            <
// 00000128: 44 69 73 70 49 64 41 74  74 72 69 62 75 74 65 00 >DispIdAttribute <
// 00000138: 53 75 6d 4f 66 54 77 6f  49 6e 74 65 67 65 72 73 >SumOfTwoIntegers<
//         : 00                                               >                <
// 00000149: 5f 5f 4d 49 44 4c 5f 5f  49 4d 79 4d 61 74 68 30 >__MIDL__IMyMath0<
//         : 30 30 30 00                                      >000             <
// 0000015d: 5f 5f 4d 49 44 4c 5f 5f  49 4d 79 4d 61 74 68 30 >__MIDL__IMyMath0<
//         : 30 30 31 00                                      >001             <
// 00000171: 53 75 62 74 72 61 63 74  69 6f 6e 4f 66 54 77 6f >SubtractionOfTwo<
//         : 49 6e 74 65 67 65 72 73  00                      >Integers        <
// 0000018a: 5f 5f 4d 49 44 4c 5f 5f  49 4d 79 4d 61 74 68 30 >__MIDL__IMyMath0<
//         : 30 30 33 00                                      >003             <
// 0000019e: 5f 5f 4d 49 44 4c 5f 5f  49 4d 79 4d 61 74 68 30 >__MIDL__IMyMath0<
//         : 30 30 34 00                                      >004             <
// 000001b2: 2e 63 74 6f 72 00                                >.ctor           <
// 000001b8: 41 75 74 6f 6d 61 74 69  6f 6e 53 65 72 76 65 72 >AutomationServer<
//         : 54 79 70 65 4c 69 62 46  6f 72 44 6f 74 4e 65 74 >TypeLibForDotNet<
//         : 2e 64 6c 6c 00                                   >.dll            <
// 
// User Strings
// -------------------------------------------------------
// 70000001 : ( 1) L" "
// ===========================================================
// 
// Unresolved Externals
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ===========================================================
// No warnings or errors found.
// ===========================================================
// ================================= END OF METAINFO ================================================


// Metadata version: v4.0.30319
.assembly extern /*23000001*/ mscorlib
{
  .publickeytoken = (B7 7A 5C 56 19 34 E0 89 )                         // .z\V.4..
  .ver 4:0:0:0
}
.assembly /*20000001*/ AutomationServerTypeLibForDotNet
{
  .custom /*0C000002:0A000003*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.GuidAttribute/*01000003*/::.ctor(string) /* 0A000003 */ = ( 01 00 24 46 31 34 43 38 45 32 30 2D 35 35 42 31   // ..$F14C8E20-55B1
                                                                                                                                                               2D 34 46 33 33 2D 42 35 31 38 2D 42 35 45 33 34   // -4F33-B518-B5E34
                                                                                                                                                               38 35 33 34 36 39 32 00 00 )                      // 8534692..
  .custom /*0C000003:0A000001*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.ImportedFromTypeLibAttribute/*01000001*/::.ctor(string) /* 0A000001 */ = ( 01 00 22 41 75 74 6F 6D 61 74 69 6F 6E 53 65 72   // .."AutomationSer
                                                                                                                                                                              76 65 72 57 69 74 68 52 65 67 46 69 6C 65 54 79   // verWithRegFileTy
                                                                                                                                                                              70 65 4C 69 62 00 00 )                            // peLib..
  .custom /*0C000004:0A000002*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.TypeLibVersionAttribute/*01000002*/::.ctor(int32,
                                                                                                                                              int32) /* 0A000002 */ = ( 01 00 01 00 00 00 00 00 00 00 00 00 ) 
  .hash algorithm 0x00008004
  .ver 1:0:0:0
}
.module AutomationServerTypeLibForDotNet.dll
// MVID: {D2371497-E973-44AA-A52B-5A5BE665A3F5}
.imagebase 0x00400000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003       // WINDOWS_CUI
.corflags 0x00000001    //  ILONLY
// Image base: 0x0000029810FB0000


// =============== CLASS MEMBERS DECLARATION ===================

.class /*02000002*/ interface public abstract auto ansi import AutomationServerTypeLibForDotNet.IMyMath
{
  .custom /*0C000006:0A000004*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.TypeLibTypeAttribute/*01000004*/::.ctor(valuetype [mscorlib/*23000001*/]System.Runtime.InteropServices.TypeLibTypeFlags/*01000005*/) /* 0A000004 */ = ( 01 00 40 10 00 00 00 00 )                         // ..@.....
  .custom /*0C000007:0A000003*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.GuidAttribute/*01000003*/::.ctor(string) /* 0A000003 */ = ( 01 00 24 45 43 34 34 39 43 41 30 2D 42 45 31 41   // ..$EC449CA0-BE1A
                                                                                                                                                               2D 34 35 37 31 2D 38 39 42 37 2D 46 32 45 36 31   // -4571-89B7-F2E61
                                                                                                                                                               35 33 43 45 32 34 33 00 00 )                      // 53CE243..
  .method /*06000001*/ public hidebysig newslot abstract virtual 
          instance int32  SumOfTwoIntegers([in] int32 __MIDL__IMyMath0000,
                                           [in] int32 __MIDL__IMyMath0001) runtime managed internalcall
  // SIG: 20 02 08 08 08
  {
    .custom /*0C000001:0A000007*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.DispIdAttribute/*0100000B*/::.ctor(int32) /* 0A000007 */ = ( 01 00 00 00 02 60 00 00 )                         // .....`..
  } // end of method IMyMath::SumOfTwoIntegers

  .method /*06000002*/ public hidebysig newslot abstract virtual 
          instance int32  SubtractionOfTwoIntegers([in] int32 __MIDL__IMyMath0003,
                                                   [in] int32 __MIDL__IMyMath0004) runtime managed internalcall
  // SIG: 20 02 08 08 08
  {
    .custom /*0C000005:0A000007*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.DispIdAttribute/*0100000B*/::.ctor(int32) /* 0A000007 */ = ( 01 00 01 00 02 60 00 00 )                         // .....`..
  } // end of method IMyMath::SubtractionOfTwoIntegers

} // end of class AutomationServerTypeLibForDotNet.IMyMath

.class /*02000003*/ interface public abstract auto ansi import AutomationServerTypeLibForDotNet.CMyMath
       implements AutomationServerTypeLibForDotNet.IMyMath/*02000002*/
{
  .custom /*0C000008:0A000006*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.CoClassAttribute/*01000009*/::.ctor(class [mscorlib/*23000001*/]System.Type/*0100000A*/) /* 0A000006 */ = ( 01 00 2D 41 75 74 6F 6D 61 74 69 6F 6E 53 65 72   // ..-AutomationSer
                                                                                                                                                                                                               76 65 72 54 79 70 65 4C 69 62 46 6F 72 44 6F 74   // verTypeLibForDot
                                                                                                                                                                                                               4E 65 74 2E 43 4D 79 4D 61 74 68 43 6C 61 73 73   // Net.CMyMathClass
                                                                                                                                                                                                               00 00 ) 
  .custom /*0C000009:0A000003*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.GuidAttribute/*01000003*/::.ctor(string) /* 0A000003 */ = ( 01 00 24 45 43 34 34 39 43 41 30 2D 42 45 31 41   // ..$EC449CA0-BE1A
                                                                                                                                                               2D 34 35 37 31 2D 38 39 42 37 2D 46 32 45 36 31   // -4571-89B7-F2E61
                                                                                                                                                               35 33 43 45 32 34 33 00 00 )                      // 53CE243..
} // end of class AutomationServerTypeLibForDotNet.CMyMath

.class /*02000004*/ public auto ansi import AutomationServerTypeLibForDotNet.CMyMathClass
       extends [mscorlib/*23000001*/]System.Object/*01000006*/
       implements AutomationServerTypeLibForDotNet.IMyMath/*02000002*/,
                  AutomationServerTypeLibForDotNet.CMyMath/*02000003*/
{
  .custom /*0C00000B:0A000003*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.GuidAttribute/*01000003*/::.ctor(string) /* 0A000003 */ = ( 01 00 24 34 34 45 41 35 30 31 46 2D 35 31 35 45   // ..$44EA501F-515E
                                                                                                                                                               2D 34 42 38 41 2D 38 37 38 36 2D 32 33 38 44 34   // -4B8A-8786-238D4
                                                                                                                                                               31 31 30 41 33 31 45 00 00 )                      // 110A31E..
  .custom /*0C00000C:0A000005*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.ClassInterfaceAttribute/*01000007*/::.ctor(valuetype [mscorlib/*23000001*/]System.Runtime.InteropServices.ClassInterfaceType/*01000008*/) /* 0A000005 */ = ( 01 00 00 00 00 00 00 00 ) 
  .custom /*0C00000D:0A000004*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.TypeLibTypeAttribute/*01000004*/::.ctor(valuetype [mscorlib/*23000001*/]System.Runtime.InteropServices.TypeLibTypeFlags/*01000005*/) /* 0A000004 */ = ( 01 00 02 00 00 00 00 00 ) 
  .method /*06000003*/ public specialname rtspecialname 
          instance void  .ctor() runtime managed internalcall
  // SIG: 20 00 01
  {
  } // end of method CMyMathClass::.ctor

  .method /*06000004*/ public hidebysig newslot virtual 
          instance int32  SumOfTwoIntegers([in] int32 __MIDL__IMyMath0000,
                                           [in] int32 __MIDL__IMyMath0001) runtime managed internalcall
  // SIG: 20 02 08 08 08
  {
    .custom /*0C00000A:0A000007*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.DispIdAttribute/*0100000B*/::.ctor(int32) /* 0A000007 */ = ( 01 00 00 00 02 60 00 00 )                         // .....`..
    .override AutomationServerTypeLibForDotNet.IMyMath/*02000002*/::SumOfTwoIntegers /*02000002::06000001*/ 
  } // end of method CMyMathClass::SumOfTwoIntegers

  .method /*06000005*/ public hidebysig newslot virtual 
          instance int32  SubtractionOfTwoIntegers([in] int32 __MIDL__IMyMath0003,
                                                   [in] int32 __MIDL__IMyMath0004) runtime managed internalcall
  // SIG: 20 02 08 08 08
  {
    .custom /*0C00000E:0A000007*/ instance void [mscorlib/*23000001*/]System.Runtime.InteropServices.DispIdAttribute/*0100000B*/::.ctor(int32) /* 0A000007 */ = ( 01 00 01 00 02 60 00 00 )                         // .....`..
    .override AutomationServerTypeLibForDotNet.IMyMath/*02000002*/::SubtractionOfTwoIntegers /*02000002::06000002*/ 
  } // end of method CMyMathClass::SubtractionOfTwoIntegers

} // end of class AutomationServerTypeLibForDotNet.CMyMathClass


// =============================================================

// *********** DISASSEMBLY COMPLETE ***********************
// WARNING: Created Win32 resource file H:\Microsoft Visual Studio\2019\Community\MyProjects - WinDev2021\02-COM\04-Automation\AutomationClients\DotNet\CSharp\Temp.res
