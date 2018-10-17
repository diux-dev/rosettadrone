/*
 * SpanDSP - a series of DSP components for telephony
 *
 * private/t4_rx.h - definitions for T.4 FAX receive processing
 *
 * Written by Steve Underwood <steveu@coppice.org>
 *
 * Copyright (C) 2003 Steve Underwood
 *
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(_SPANDSP_PRIVATE_T4_RX_H_)
#define _SPANDSP_PRIVATE_T4_RX_H_

#define t4_rx_state_s t4_state_s

/*!
    T.4 FAX decompression metadata descriptor. This contains information about the image
    which may be relevant to the backend, but is not relevant to the image decoding process.
*/
typedef struct
{
    /*! \brief The vendor of the machine which produced the file. */ 
    const char *vendor;
    /*! \brief The model of machine which produced the file. */ 
    const char *model;
    /*! \brief The local ident string. */ 
    const char *local_ident;
    /*! \brief The remote end's ident string. */ 
    const char *far_ident;
    /*! \brief The FAX sub-address. */ 
    const char *sub_address;
    /*! \brief The FAX DCS information, as an ASCII hex string. */ 
    const char *dcs;
} t4_rx_metadata_t;

/*!
    TIFF specific state information to go with T.4 compression or decompression handling.
*/
typedef struct
{
    /*! \brief The current file name. */
    const char *file;
    /*! \brief The libtiff context for the current TIFF file */
    TIFF *tiff_file;

    /* Supporting information, like resolutions, which the backend may want. */
    t4_rx_metadata_t metadata;

    /*! \brief The compression type for output to the TIFF file. */
    int32_t output_compression;
    /*! \brief The TIFF photometric setting for the current page. */
    uint16_t photo_metric;
    /*! \brief The TIFF fill order setting for the current page. */
    uint16_t fill_order;
    /*! \brief The TIFF G3 FAX options. */
    int32_t output_t4_options;

    /*! \brief The number of pages in the current image file. */
    int pages_in_file;

    /*! \brief The first page to transfer. -1 to start at the beginning of the file. */
    int start_page;
    /*! \brief The last page to transfer. -1 to continue to the end of the file. */
    int stop_page;
} t4_tiff_state_t;

#endif
/*- End of file ------------------------------------------------------------*/
