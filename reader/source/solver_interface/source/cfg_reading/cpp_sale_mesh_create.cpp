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

extern "C"
{

// Not implemented in the open reader.
//
// The real entry point builds a structured ALE mesh: it creates the elements
// and nodes of an /ALE/STRUCTURED_MESH and fills MESSAGE_VALUE with the ids,
// counts and offsets it produced (see hm_s_ale.F90 for the layout of the 45
// slots). None of that exists here.
//
// Only decks carrying /ALE/STRUCTURED_MESH reach this function at all, so the
// gap is narrow and named. MESSAGE_VALUE is left as the caller initialised
// it, all zeros: no mesh, no offsets. Slot 38 carries an error id, but every
// id it accepts is mapped to a fixed text in s_ale_message.F90 ("invalid part
// id", "invalid control point id", ...). Any of them would state a reason
// that is not the true one, so none is used; the message below says what
// actually happened.
CDECL void cpp_sale_mesh_create_(int *MESSAGE_VALUE)
{
    printf("\n");
    printf(" ** OPEN READER: cpp_sale_mesh_create is not implemented.\n");
    printf("    /ALE/STRUCTURED_MESH is NOT expanded into elements and nodes.\n");
    printf("    Use the prebuilt reader from extlib for production runs.\n");
    printf("\n");
    fflush(stdout);
}

CDECL void CPP_SALE_MESH_CREATE(int *MESSAGE_VALUE)
{cpp_sale_mesh_create_ (MESSAGE_VALUE);}

CDECL void cpp_sale_mesh_create__(int *MESSAGE_VALUE)
{cpp_sale_mesh_create_ (MESSAGE_VALUE);}

CDECL void cpp_sale_mesh_create(int *MESSAGE_VALUE)
{cpp_sale_mesh_create_ (MESSAGE_VALUE);}


}
