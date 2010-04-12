#ifndef __MuscleViaPoint_h__
#define __MuscleViaPoint_h__

// ConditionalPathPoint.h
// Author: Peter Loan
/*
 * Copyright (c)  2006, Stanford University. All rights reserved. 
* Use of the OpenSim software in source form is permitted provided that the following
* conditions are met:
* 	1. The software is used only for non-commercial research and education. It may not
*     be used in relation to any commercial activity.
* 	2. The software is not distributed or redistributed.  Software distribution is allowed 
*     only through https://simtk.org/home/opensim.
* 	3. Use of the OpenSim software or derivatives must be acknowledged in all publications,
*      presentations, or documents describing work in which OpenSim or derivatives are used.
* 	4. Credits to developers may not be removed from executables
*     created from modifications of the source.
* 	5. Modifications of source code must retain the above copyright notice, this list of
*     conditions and the following disclaimer. 
* 
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
*  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
*  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
*  SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
*  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
*  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR BUSINESS INTERRUPTION) OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
*  WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


// INCLUDE
#include <iostream>
#include <string>
#include <math.h>
#include <OpenSim/Simulation/osimSimulationDLL.h>
#include <OpenSim/Common/VisibleObject.h>
#include <OpenSim/Common/PropertyDblArray.h>
#include <OpenSim/Common/PropertyStr.h>
#include <OpenSim/Common/Storage.h>
#include <OpenSim/Simulation/Model/PathPoint.h>

#ifdef SWIG
	#ifdef OSIMSIMULATION_API
		#undef OSIMSIMULATION_API
		#define OSIMSIMULATION_API
	#endif
#endif

namespace OpenSim {

class Coordinate;
class Model;
class GeometryPath;
class SimbodyEngine;

//=============================================================================
//=============================================================================
/**
 * A class implementing a conditional path point, which is a point that
 * is active only for a specified range of a coordinate.
 *
 * @author Peter Loan
 * @version 1.0
 */
class OSIMSIMULATION_API ConditionalPathPoint : public PathPoint  
{

//=============================================================================
// DATA
//=============================================================================
private:

protected:
   PropertyDblArray _rangeProp;
   Array<double> &_range;

	PropertyStr _coordinateNameProp;
   std::string &_coordinateName;

	const Coordinate* _coordinate;

//=============================================================================
// METHODS
//=============================================================================
	//--------------------------------------------------------------------------
	// CONSTRUCTION
	//--------------------------------------------------------------------------
public:
	ConditionalPathPoint();
	ConditionalPathPoint(const ConditionalPathPoint &aPoint);
	virtual ~ConditionalPathPoint();
	virtual Object* copy() const;

#ifndef SWIG
	ConditionalPathPoint& operator=(const ConditionalPathPoint &aPoint);
#endif
   void copyData(const ConditionalPathPoint &aPoint);
	virtual void init(const PathPoint& aPoint);
	virtual void updateFromXMLNode();

	Array<double>& getRange() const { return _range; }
	const Coordinate* getCoordinate() const { return _coordinate; }
	const std::string& getCoordinateName() const { return _coordinateName; }
#ifndef SWIG
	void setCoordinate(const SimTK::State& s, Coordinate& aCoordinate);
	void setRangeMin( const SimTK::State& s, double aMin);
	void setRangeMax( const SimTK::State& s, double aMax);

	virtual bool isActive(const SimTK::State& s) const;
	virtual void setup(const Model& aModel, GeometryPath& aPath);
#endif
	OPENSIM_DECLARE_DERIVED(ConditionalPathPoint, PathPoint);
private:
	void setNull();
	void setupProperties();
//=============================================================================
};	// END of class ConditionalPathPoint
//=============================================================================
//=============================================================================

} // end of namespace OpenSim

#endif // __MuscleViaPoint_h__

