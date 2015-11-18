/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#ifndef foosdipv4llfoo
#define foosdipv4llfoo

/***
  This file is part of systemd.

  Copyright (C) 2014 Axis Communications AB. All rights reserved.

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <netinet/in.h>
#include <net/ethernet.h>

#include "sd-event.h"
#include "_sd-common.h"

_SD_BEGIN_DECLARATIONS;

enum {
        SD_IPV4LL_EVENT_STOP            = 0,
        SD_IPV4LL_EVENT_BIND            = 1,
        SD_IPV4LL_EVENT_CONFLICT        = 2,
};

typedef struct sd_ipv4ll sd_ipv4ll;
typedef void (*sd_ipv4ll_cb_t)(sd_ipv4ll *ll, int event, void *userdata);

int sd_ipv4ll_detach_event(sd_ipv4ll *ll);
int sd_ipv4ll_attach_event(sd_ipv4ll *ll, sd_event *event, int priority);
int sd_ipv4ll_get_address(sd_ipv4ll *ll, struct in_addr *address);
int sd_ipv4ll_set_callback(sd_ipv4ll *ll, sd_ipv4ll_cb_t cb, void *userdata);
int sd_ipv4ll_set_mac(sd_ipv4ll *ll, const struct ether_addr *addr);
int sd_ipv4ll_set_index(sd_ipv4ll *ll, int interface_index);
int sd_ipv4ll_set_address(sd_ipv4ll *ll, const struct in_addr *address);
int sd_ipv4ll_set_address_seed(sd_ipv4ll *ll, unsigned seed);
int sd_ipv4ll_is_running(sd_ipv4ll *ll);
int sd_ipv4ll_start(sd_ipv4ll *ll);
int sd_ipv4ll_stop(sd_ipv4ll *ll);
sd_ipv4ll *sd_ipv4ll_ref(sd_ipv4ll *ll);
sd_ipv4ll *sd_ipv4ll_unref(sd_ipv4ll *ll);
int sd_ipv4ll_new (sd_ipv4ll **ret);

_SD_END_DECLARATIONS;

#endif
