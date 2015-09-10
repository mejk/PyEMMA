/*
* This file is part of thermotools.
*
* Copyright 2015 Computational Molecular Biology Group, Freie Universitaet Berlin (GER)
*
* thermotools is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <math.h>
#include "_bar.h"
#include "../lse/_lse.h"

extern double _df(double *dbIJ, int L1, double *dbJI, int L2, double *scratch)
{
    int i;
    double ln_avg1;
    double ln_avg2; 
    for (i=0; i<L1; i++)
    {
        scratch[i] = dbIJ[i]>0 ? 0 : dbIJ[i];
    }
    ln_avg1 = logsumexp(scratch, L1);
    for (i=0; i<L1; i++)
    {
        scratch[i] = dbJI[i]>0 ? 0 : dbJI[i];
    }
    ln_avg2 = logsumexp(scratch, L2);

    return ln_avg2 - ln_avg1;
}