// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2011 XORP, Inc and Others
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, Version 2, June
// 1991 as published by the Free Software Foundation. Redistribution
// and/or modification of this program under the terms of any other
// version of the GNU General Public License is not permitted.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU General Public License, Version 2, a copy of which can be
// found in the XORP LICENSE.gpl file.
// 
// XORP Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
// http://xorp.net



#include "fea/fea_module.h"

#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"

#include "fea/fibconfig.hh"

#include "fibconfig_entry_observer_rtmv2.hh"


//
// Observe single-entry information change about the unicast forwarding table.
//
// E.g., if the forwarding table has changed, then the information
// received by the observer would specify the particular entry that
// has changed.
//
// The mechanism to observe the information is Router Manager V2.
//

#ifdef HOST_OS_WINDOWS

FibConfigEntryObserverRtmV2::FibConfigEntryObserverRtmV2(FeaDataPlaneManager& fea_data_plane_manager)
    : FibConfigEntryObserver(fea_data_plane_manager)
#if 0
      WinRtmPipe(fea_data_plane_manager.eventloop()),
      WinRtmPipeObserver(*(WinRtmPipe *)this)
#endif
{
}

FibConfigEntryObserverRtmV2::~FibConfigEntryObserverRtmV2()
{
    string error_msg;

    if (stop(error_msg) != XORP_OK) {
	XLOG_ERROR("Cannot stop the Router Manager V2 mechanism to observe "
		   "information about forwarding table from the underlying "
		   "system: %s",
		   error_msg.c_str());
    }
}

int
FibConfigEntryObserverRtmV2::start(string& error_msg)
{
#if 0
    if (_is_running)
	return (XORP_OK);

    if (WinRtmPipe::start(error_msg) != XORP_OK)
	return (XORP_ERROR);

    _is_running = true;
#endif
    return (XORP_OK);
    UNUSED(error_msg);
}

int
FibConfigEntryObserverRtmV2::stop(string& error_msg)
{
#if 0
    if (! _is_running)
	return (XORP_OK);

    if (WinRtmPipe::stop(error_msg) != XORP_OK)
	return (XORP_ERROR);

    _is_running = false;
#endif

    return (XORP_OK);
    UNUSED(error_msg);
}

#if 0
void
FibConfigEntryObserverRtmV2::receive_data(const vector<uint8_t>& buffer)
{
    // TODO: XXX: PAVPAVPAV: use it?
    UNUSED(buffer);
}

void
FibConfigEntryObserverRtmV2::routing_socket_data(const vector<uint8_t>& buffer)
{
    receive_data(buffer);
}
#endif // 0

#endif // HOST_OS_WINDOWS
