//
// Copyright (C) 2004 Andras Varga
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//


#ifndef __INET_IPTRAFSINK_H
#define __INET_IPTRAFSINK_H

#include <vector>

#include "INETDefs.h"
#include "IPvXAddress.h"
#include "ILifecycle.h"


/**
 * Consumes and prints packets received from the IP module. See NED for more info.
 */
class INET_API IPvXTrafSink : public cSimpleModule, public ILifecycle
{
  protected:
    int numReceived;
    bool isOperational;
    static simsignal_t rcvdPkSignal;

    virtual void printPacket(cPacket *msg);
    virtual void processPacket(cPacket *msg);

  public:
    virtual bool handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback);

  protected:
    virtual void initialize(int stage);
    virtual int numInitStages() const { return 2; }
    virtual void handleMessage(cMessage *msg);
};

#endif

