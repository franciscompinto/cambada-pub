/*
 *  Gazebo - Outdoor Multi-Robot Simulator
 *  Copyright (C) 2003  
 *     Nate Koenig & Andrew Howard
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/* Desc: Specification of a contact
 * Author: Nate Koenig
 * Date: 10 Nov 2009
 * SVN: $Id$
 *
 * Modified by: Eurico Pedrosa <efp@ua.p>
 * Date: 10 Fev 2010
 *
 * Modification Notes
 *
 *  The modifications presented by me, have the purpose of
 *  removing the 'rendering' and 'gui' modules from the code base.
 *  The reasons behind this decision are simple, allow gazebo to run
 *  on computers with less gpu capabilities and lessen the the coupling
 *  between simulation and visualization.
 *
 */

#ifndef CONTACT_HH
#define CONTACT_HH

#include <vector>

#include "Time.hh"
#include "Vector3.hh"
#include "JointFeedback.hh"

namespace gazebo
{
  class Geom;
 
  /// \brief A contact between two geoms. Each contact can consist of
  ///        a numnber of contact points 
  class Contact
  {
    /// \brief Constructor
    public: Contact();

    /// \brief Copy constructor
    public: Contact(const Contact &c);

    /// \brief Destructor
    public: virtual ~Contact();

    /// \brief Clone the contact
    public: Contact Clone() const;
  
    /// \brief Operator =
    public: const Contact &operator=(const Contact &contact);

    /// \brief Reset
    public: void Reset();
  
    public: Geom *geom1;
    public: Geom *geom2;
 
    public: std::vector<JointFeedback> forces;

    public: std::vector<Vector3> positions;
    public: std::vector<Vector3> normals;
  
    public: std::vector<double> depths;

    public: Time time;
  };
}

#endif
