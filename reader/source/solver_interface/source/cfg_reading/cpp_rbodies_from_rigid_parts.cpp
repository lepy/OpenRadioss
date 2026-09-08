//Copyright>        OpenRadioss
//Copyright>        Copyright (C) 2026 Siemens
//Copyright>
//Copyright>        This program is free software: you can redistribute it and/or modify
//Copyright>        it under the terms of the GNU Affero General Public License as published by
//Copyright>        the Free Software Foundation, either version 3 of the License, or
//Copyright>        (at your option) any later version.
//Copyright>
//Copyright>        This program is distributed in the hope that it will be useful,
//Copyright>        but WITHOUT ANY WARRANTY; without even the implied warranty of
//Copyright>        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//Copyright>        GNU Affero General Public License for more details.
//Copyright>
//Copyright>        You should have received a copy of the GNU Affero General Public License
//Copyright>        along with this program.  If not, see <https://www.gnu.org/licenses/>.
//Copyright>
//Copyright>
//Copyright>        Commercial Alternative: Simcenter Radioss Software
//Copyright>
//Copyright>        As an alternative to this open-source version, Siemens also offers Simcenter(TM) Radioss(R)
//Copyright>        software under a commercial license.  Contact Siemens to discuss further if the
//Copyright>        commercial version may interest you: 
//Copyright>        https://www.siemens.com/en-us/products/simcenter/mechanical-simulation/radioss/.

#include "GlobalModelSDI.h"

#include <stdio.h>
#include <string.h>
#include <dll_settings.h>

using namespace std;

// Not implemented in the open reader.
//
// The starter creates one /RBODY per /PART carrying Irigid, a notion that
// lives inside the conversion and is not part of the open reader. Both entry
// points below therefore report "nothing to create" and say so once, loudly:
// a build with -open_reader is a development build, and a model that relies
// on rigid parts is converted without them.
//
// Returning zero is the only answer that cannot be misread. The alternative,
// an error id, would be worse: s_ale_message.F90 and its siblings map ids to
// fixed texts, so any id invented here would make the starter report a reason
// that is not the true one.
static void warnOnce(const char *entryPoint)
{
    static bool alreadyWarned = false;
    if (alreadyWarned) return;
    alreadyWarned = true;
    printf("\n");
    printf(" ** OPEN READER: %s is not implemented.\n", entryPoint);
    printf("    /RBODY entities are NOT created from rigid parts.\n");
    printf("    Use the prebuilt reader from extlib for production runs.\n");
    printf("\n");
    fflush(stdout);
}

extern "C"
{

CDECL void cpp_evaluate_rbodies_number_from_rigid_parts_(int *NBRBODIES_PER_PART)
{
    warnOnce("cpp_evaluate_rbodies_number_from_rigid_parts");
    // The caller zeroed the array and sums it; leaving it alone yields zero
    // new rigid bodies, and cpp_create_rbodies_from_rigid_parts is then
    // called with an empty array.
}

CDECL void CPP_EVALUATE_RBODIES_NUMBER_FROM_RIGID_PARTS(int *NBRBODIES_PER_PART)
{cpp_evaluate_rbodies_number_from_rigid_parts_ (NBRBODIES_PER_PART);}

CDECL void cpp_evaluate_rbodies_number_from_rigid_parts__(int *NBRBODIES_PER_PART)
{cpp_evaluate_rbodies_number_from_rigid_parts_ (NBRBODIES_PER_PART);}

CDECL void cpp_evaluate_rbodies_number_from_rigid_parts(int *NBRBODIES_PER_PART)
{cpp_evaluate_rbodies_number_from_rigid_parts_ (NBRBODIES_PER_PART);}


CDECL void cpp_create_rbodies_from_rigid_parts_(int *NEW_RBODY_TO_PART, int *NEW_RBODY_ID)
{
    warnOnce("cpp_create_rbodies_from_rigid_parts");
    // Reached only with an empty array, since the evaluate entry point above
    // reports no rigid bodies. Nothing to fill.
}

CDECL void CPP_CREATE_RBODIES_FROM_RIGID_PARTS(int *NEW_RBODY_TO_PART, int *NEW_RBODY_ID)
{cpp_create_rbodies_from_rigid_parts_ (NEW_RBODY_TO_PART, NEW_RBODY_ID);}

CDECL void cpp_create_rbodies_from_rigid_parts__(int *NEW_RBODY_TO_PART, int *NEW_RBODY_ID)
{cpp_create_rbodies_from_rigid_parts_ (NEW_RBODY_TO_PART, NEW_RBODY_ID);}

CDECL void cpp_create_rbodies_from_rigid_parts(int *NEW_RBODY_TO_PART, int *NEW_RBODY_ID)
{cpp_create_rbodies_from_rigid_parts_ (NEW_RBODY_TO_PART, NEW_RBODY_ID);}


}
