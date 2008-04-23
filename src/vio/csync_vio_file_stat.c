/*
 * libcsync -- a library to sync a directory with another
 *
 * Copyright (c) 2008      by Andreas Schneider <mail@cynapses.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * vim: ts=2 sw=2 et cindent
 */

#include "c_lib.h"
#include "vio/csync_vio_file_stat.h"

csync_vio_file_stat_t *csync_vio_file_stat_new(void) {
  csync_vio_file_stat_t *file_stat = NULL;

  file_stat = (csync_vio_file_stat_t *) c_malloc(sizeof(csync_vio_file_stat_t));
  if (file_stat == NULL) {
    return NULL;
  }

  return file_stat;
}

void csync_vio_file_stat_destroy(csync_vio_file_stat_t *file_stat) {
  /* FIXME: free rest */
  if (file_stat == NULL) {
    return;
  }

  if (file_stat->fields == CSYNC_VIO_FILE_STAT_FIELDS_SYMLINK_NAME) {
    SAFE_FREE(file_stat->symlink_name);
  }
  SAFE_FREE(file_stat->name);
  SAFE_FREE(file_stat);
}

