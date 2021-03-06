/*********************************************************************
*                SEGGER MICROCONTROLLER GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 2003-2010     SEGGER Microcontroller GmbH & Co KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

**** emFile file system for embedded applications ****
emFile is protected by international copyright laws. Knowledge of the
source code may not be used to write a similar product. This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : FAT_Intern.h
Purpose     : Internal FAT File System Layer header
---------------------------END-OF-HEADER------------------------------
*/

#ifndef _FAT_INTERN_H_               // Avoid recursive and multiple inclusion
#define _FAT_INTERN_H_

#include "FS_Int.h"
#include "FAT.h"


#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       #define constants
*
**********************************************************************
*/

/*********************************************************************
*
*       defines non configurable
*
**********************************************************************
*/
#define FAT_FIRST_CLUSTER        (2)

#define FS_FAT_DENTRY_SIZE       0x20
#define FS_FAT_DENTRY_SIZE_SHIFT 0x05


#define FS_FAT_ATTR_READ_ONLY    FS_ATTR_READ_ONLY
#define FS_FAT_ATTR_HIDDEN       FS_ATTR_HIDDEN
#define FS_FAT_ATTR_SYSTEM       FS_ATTR_SYSTEM
#define FS_FAT_ATTR_VOLUME_ID    0x08
#define FS_FAT_ATTR_ARCHIVE      FS_ATTR_ARCHIVE
#define FS_FAT_ATTR_DIRECTORY    FS_ATTR_DIRECTORY
#define FS_FAT_ATTR_LONGNAME     (FS_FAT_ATTR_READ_ONLY | FS_FAT_ATTR_HIDDEN | FS_FAT_ATTR_SYSTEM | FS_FAT_ATTR_VOLUME_ID)
#define FS_FAT_ATTR_MASK         (FS_FAT_ATTR_READ_ONLY | FS_FAT_ATTR_HIDDEN | FS_FAT_ATTR_SYSTEM | FS_FAT_ATTR_VOLUME_ID | FS_FAT_ATTR_ARCHIVE | FS_FAT_ATTR_DIRECTORY)

#define FS_FAT_MAX_DIRNAME      255

#define FS_FAT_TYPE_FAT12       12
#define FS_FAT_TYPE_FAT16       16
#define FS_FAT_TYPE_FAT32       32

#define INVALID_NUM_FREE_CLUSTERS_VALUE   0xFFFFFFFFUL


/*********************************************************************
*
*       defines for Boot parameter block offsets
*
**********************************************************************
*/
#define BPB_OFF_SIGNATURE          510
#define BPB_OFF_BYTES_PER_SECTOR    11
#define BPB_OFF_NUM_FATS            16
#define BPB_OFF_SECTOR_PER_CLUSTER  13
#define BPB_OFF_NUMSECTORS_16BIT    19
#define BPB_OFF_NUMSECTORS_32BIT    32
#define BPB_OFF_FATSIZE_16BIT       22
#define BPB_OFF_FATSIZE_32BIT       36
#define BPB_OFF_FAT32_EXTFLAGS      40
#define BPB_OFF_ROOTDIR_CLUSTER     44
#define BPB_OFF_FAT32_FSINFO_SECTOR 48

/*********************************************************************
*
*       defines for FAT32 FSInfo Sector offsets
*
**********************************************************************
*/
#define FSINFO_OFF_SIGNATURE_1            0
#define FSINFO_OFF_SIGNATURE_2          484
#define FSINFO_OFF_FREE_CLUSTERS        488
#define FSINFO_OFF_NEXT_FREE_CLUSTER    492
#define FSINFO_OFF_SIGNATURE_3          508

/*********************************************************************
*
*       defines for FAT32 FSInfo related values
*
**********************************************************************
*/
#define FSINFO_SIGNATURE_1                       0x41615252UL
#define FSINFO_SIGNATURE_2                       0x61417272UL
#define FSINFO_SIGNATURE_3                       0xAA550000UL

/*********************************************************************
*
*       defines for directory entry offsets
*
**********************************************************************
*/
#define DIR_ENTRY_OFF_EXTENSION            8
#define DIR_ENTRY_OFF_ATTRIBUTES          11
#define DIR_ENTRY_OFF_SIZE                28
#define DIR_ENTRY_OFF_FIRSTCLUSTER_LOW    26
#define DIR_ENTRY_OFF_FIRSTCLUSTER_HIGH   20
#define DIR_ENTRY_OFF_CREATION_TIME       14
#define DIR_ENTRY_OFF_CREATION_DATE       16
#define DIR_ENTRY_OFF_LAST_ACCESS_DATE    18
#define DIR_ENTRY_OFF_WRITE_TIME          22
#define DIR_ENTRY_OFF_WRITE_DATE          24

#define DIR_ENTRY_SHIFT                    5

/*********************************************************************
*
*             Global data types
*
**********************************************************************
*/

/* FAT directory entry */
typedef struct {
  U8   FAT_data[FS_FAT_DENTRY_SIZE];	//khe
} FS_FAT_DENTRY;

typedef struct {
  char ac[11];
} FS_83NAME;

/*********************************************************************
*
*             Global function prototypes
*
**********************************************************************
*/

/*********************************************************************
*
*       FAT_Misc
*/
U32          FS_FAT_ClusterId2SectorNo      (FS_FAT_INFO xdata * pFATInfo, U32 ClusterId);
U32          FS_FAT_FindFreeCluster         (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 FirstCluster, FS_FILE xdata * pFile);
void         FS_FAT_LinkCluster             (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 LastCluster, U32 NewCluster);
char         FS_FAT_MarkClusterEOC          (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 Cluster);
U32          FS_FAT_WalkCluster             (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 StartCluster, U32 NumClusters);
U32          FS_FAT_WalkClusterEx           (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 Cluster, U32 * pNumClusters);
U32          FS_FAT_AllocCluster            (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 LastCluster, FS_FILE xdata * pFile);
U32          FS_FAT_ReadFATEntry            (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 ClusterId);
U32          FS_FAT_FindLastCluster         (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 ClusterId, U32 * pNumClusters);
U32          FS_FAT_FreeClusterChain        (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 ClusterId, U32 NumClusters);

U16          FS_FAT_GetNumAdjClustersInChain(FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 CurCluster);
int          FS_FAT_GotoCluster             (FS_FILE   xdata * pFile,   FS_SB xdata * pSBfat);

int          FS_FAT_GotoClusterAllocIfReq   (FS_FILE   xdata * pFile,   FS_SB xdata * pSBfat);
int          FS_FAT_AllocClusterBlock       (FS_VOLUME xdata * pVolume, U32 FirstCluster, U32 NumClusters, FS_SB xdata * pSB);

FS_FAT_DENTRY xdata * FS_FAT_FindDirEntryShort    (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * pEntryName, U16 Len, U32 DirStart, U8 AttrMask);
FS_FAT_DENTRY xdata * FS_FAT_FindDirEntryShortEx  (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * pEntryName, U16 Len, FS_DIR_POS xdata * pDirPos, U8 AttrMask);
FS_FAT_DENTRY xdata * FS_FAT_FindEmptyDirEntry    (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 DirStart);
FS_FAT_DENTRY xdata * FS_FAT_GetDirEntry          (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, FS_DIR_POS xdata * pDirPos);
FS_FAT_DENTRY xdata * FS_FAT_FindDirEntry         (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char *pEntryName, U16 Len, U32 DirStart, U8 AttrMask, I32 * pLongDirEntryIndex);

void         FS_FAT_IncDirPos               (FS_DIR_POS xdata * pDirPos);
char         FS_FAT_GetFATType              (U32 NumClusters);
void         FS_FAT_WriteDirEntryCluster    (FS_FAT_DENTRY xdata * pDirEntry, U32 Cluster);
U32          FS_FAT_GetFirstCluster         (FS_FAT_DENTRY xdata * pDirEntry);
void         FS_FAT_WriteDirEntry83         (FS_FAT_DENTRY xdata * pDirEntry, const FS_83NAME * pFileName, U32 ClusterId, U8 Attrib, U32 Size, U16 Time, U16 Date);
void         FS_FAT_WriteDirEntryShort      (FS_FAT_DENTRY xdata * pDirEntry, const char      * pFileName, U32 ClusterId, U8 Attrib, U32 Size, U16 Time, U16 Date);


char         FS_FAT_FindPath                (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * pFullName, const char ** ppFileName, U32 * pDirStart);
char         FS_FAT_DeleteFileOrDir         (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, FS_FAT_DENTRY xdata * pDirEntry, U8 IsFile);
void         FS_FAT_InitDirEntryScan        (FS_FAT_INFO xdata * pFATInfo, FS_DIR_POS xdata * pDirPos, U32 DirCluster);
char         FS_FAT_Make83Name              (FS_83NAME * pOutName, const char * pOrgName, U16 Len);

void         FS_FAT_UpdateDirEntry          (FS_FILE_OBJ xdata * pFileObj, FS_SB xdata * pSB);
void         FS_FAT_SyncFAT                 (FS_VOLUME   xdata * pVolume,  FS_SB xdata * pSB);
//
// File buffer related functions
//
#if FS_USE_FILE_BUFFER
  void FS_FAT_CleanWriteBuffer(FS_FILE xdata * pFile, const U8 xdata * pData, I32 NumBytesData, FS_SB xdata * pSBData);
#endif

/*********************************************************************
*
*             FAT_Move
*/
char         FS__FAT_Move                   (FS_VOLUME xdata * pVolume, U32 DirStartOld, U32 DirStartNew, const char * sOldName, const char * sNewName, FS_SB xdata * pSB);


/*********************************************************************
*
*       Directory handling
*/
int          FS_FAT_CreateDirEx             (FS_VOLUME xdata * pVolume, const char * pDirName, U32 DirStart, FS_SB xdata * pSB);

/*********************************************************************
*
*       String handling
*/
int  FS_FAT_IsValidShortNameChar(U8 c);
void FS_FAT_CopyShortName       (char * pDest, const char* pSrc, int MaxNumBytes);
void FS_FAT_CopyDirEntryInfo    (FS_FAT_DENTRY xdata * pDirEntry, FS_DIRENTRY_INFO xdata * pDirEntryInfo);

/*********************************************************************
*
*       Directory operations (8.3 file name)
*
**********************************************************************
*/
int                   SFN__ReadDirEntryInfo(FS__DIR xdata * pDir, FS_DIRENTRY_INFO xdata * pDirEntryInfo, FS_SB xdata * pSB);
FS_FAT_DENTRY xdata * SFN__FindDirEntry    (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * pEntryName, int Len, U32 DirStart, U8 AttrRequired, I32 * pLongDirEntryIndex);
FS_FAT_DENTRY xdata * SFN__CreateDirEntry  (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * pFileName, U32 DirStart, U32 ClusterId, U8 Attributes, U32 Size, U16 Time, U16 Date);

/*********************************************************************
*
*       Directory operations (long file name)
*
**********************************************************************
*/
int                   LFN__ReadDirEntryInfo(FS__DIR xdata * pDir, FS_DIRENTRY_INFO xdata * pDirEntryInfo, FS_SB xdata * pSB);
FS_FAT_DENTRY xdata * LFN__FindDirEntry    (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * sLongName, int Len, U32 DirStart, U8 AttrRequired, I32 * pLongDirEntryIndex);
FS_FAT_DENTRY xdata * LFN__CreateDirEntry  (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, const char * pFileName, U32 DirStart, U32 ClusterId, U8 Attribute, U32 Size, U16 Time, U16 Date);
void                  LFN__DelLongEntry    (FS_VOLUME xdata * pVolume, FS_SB xdata * pSB, U32 DirStart, I32 LongDirEntryIndex);


#if defined(__cplusplus)
}                /* Make sure we have C-declarations in C++ programs */
#endif

#endif  // Avoid recursive and multiple inclusion

/*************************** End of file ****************************/
