/* $Id: isoextent.h 111334 2025-10-12 01:13:33Z knut.osmundsen@oracle.com $ */
/** @file
 * IPRT - Allocation Extent structure shared by various ISO & UDF code.
 */

/*
 * Copyright (C) 2017-2025 Oracle and/or its affiliates.
 *
 * This file is part of VirtualBox base platform packages, as
 * available from https://www.virtualbox.org.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, in version 3 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses>.
 *
 * The contents of this file may alternatively be used under the terms
 * of the Common Development and Distribution License Version 1.0
 * (CDDL), a copy of it is provided in the "COPYING.CDDL" file included
 * in the VirtualBox distribution, in which case the provisions of the
 * CDDL are applicable instead of those of the GPL.
 *
 * You may elect to license modified versions of this file under the
 * terms and conditions of either the GPL or the CDDL or both.
 *
 * SPDX-License-Identifier: GPL-3.0-only OR CDDL-1.0
 */

#ifndef IPRT_INCLUDED_SRC_common_fs_isoextent_h
#define IPRT_INCLUDED_SRC_common_fs_isoextent_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

/**
 * ISO extent (internal to the VFS not a disk structure).
 *
 * Used by the UDF helper code as well as the ISO VFS code.
 */
typedef struct RTFSISOEXTENT
{
    /** The disk or partition byte offset.
     * This is set to UINT64_MAX for parts of sparse files that aren't recorded.*/
    uint64_t            off;
    /** The size of the extent in bytes. */
    uint64_t            cbExtent;
    /** UDF virtual partition number, UINT32_MAX for ISO 9660. */
    uint32_t            idxPart;
    /** Reserved.   */
    uint32_t            uReserved;
} RTFSISOEXTENT;
/** Pointer to an ISO 9660 extent. */
typedef RTFSISOEXTENT *PRTFSISOEXTENT;
/** Pointer to a const ISO 9660 extent. */
typedef RTFSISOEXTENT const *PCRTFSISOEXTENT;

#endif /* !IPRT_INCLUDED_SRC_common_fs_isoextent_h */

