#include <winsock2.h>
#include <cstdio>
#include <ctime>
#include <map>

#include "../RakNet/RakPeerInterface.h"
#include "../RakNet/MessageIdentifiers.h"
#include "../RakNet/BitStream.h"
#include "../RakNet/RakString.h"
#include "../RakNet/RakSleep.h"

#include "../ServerEntry.h"
#include "../Data.h"
#include "vaultmaster.h"

#define RAKNET_PORT        1660
#define RAKNET_CONNECTIONS 128

using namespace RakNet;
using namespace Data;
using namespace std;

typedef map<SystemAddress, ServerEntry> ServerMap;

class MasterServer
{

	private:
		static RakPeerInterface* peer;
		static SocketDescriptor* sockdescr;

		static ServerMap serverList;
		static void RemoveServer( SystemAddress addr );

		static DWORD WINAPI MasterThread( LPVOID data );
		static void timestamp();
		static bool thread;

	public:
		static HANDLE InitalizeRakNet();
		static void TerminateThread();

};
