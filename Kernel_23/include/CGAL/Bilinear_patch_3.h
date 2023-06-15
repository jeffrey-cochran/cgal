// Copyright (c) 1999
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL$
// $Id$
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Andreas Fabri, Stefan Schirra

#ifndef CGAL_BILINEAR_PATCH_3_H
#define CGAL_BILINEAR_PATCH_3_H

#include <CGAL/assertions.h>
#include <CGAL/Kernel/Return_base_tag.h>
#include <CGAL/Tetrahedron_3.h>
#include <CGAL/Dimension.h>

#include <type_traits>

namespace CGAL {

template <class R_>
class Bilinear_Patch_3 : public R_::Kernel_base::Bilinear_Patch_3
{
  typedef typename R_::Point_3              Point_3;
  typedef typename R_::Tetrahedron_3        Tetrahedron_3;
  typedef typename R_::Aff_transformation_3 Aff_transformation_3;

  typedef Bilinear_Patch_3                         Self;
  CGAL_static_assertion((std::is_same<Self, typename R_::Bilinear_Patch_3>::value));

public:

  typedef Dimension_tag<3>  Ambient_dimension;
  typedef Dimension_tag<2>  Feature_dimension;

  typedef typename R_::Kernel_base::Bilinear_Patch_3  Rep;

  const Rep& rep() const
  {
    return *this;
  }

  Rep& rep()
  {
    return *this;
  }

  typedef          R_                       R;

  Bilinear_Patch_3() {}

  Bilinear_Patch_3(const Rep& bp)
      : Rep(bp) {}

  Bilinear_Patch_3(const Point_3& p, const Point_3& q, const Point_3& r, const Point_3& s)
    : Rep(typename R::Construct_Bilinear_Patch_3()(Return_base_tag(), p, q, r, s)) {}

  Bilinear_Patch_3 transform(const Aff_transformation_3 &bp) const
  {
    return Bilinear_Patch_3(
        bp.transform(this->vertex(0)),
        bp.transform(this->vertex(1)),
        bp.transform(this->vertex(2)),
        bp.transform(this->vertex(3))
    );
  }

  bool has_on(const Point_3 &p) const
  {
    return R().has_on_3_object()(*this, p);
  }


  decltype(auto)
  vertex(int i) const
  {
    return R().construct_vertex_3_object()(*this, i);
  }

  decltype(auto)
  operator[](int i) const
  {
    return vertex(i);
  }

  bool is_degenerate() const
  {
    return R().is_degenerate_3_object()(*this);
  }

  Tetrahedron_3
  tetrahedron() const
  {
    return R().construct_tetrahedron_3_object()(vertex(0), vertex(1), vertex(2), vertex(3));
  }

};


template < class R >
std::ostream &
operator<<(std::ostream &os, const Bilinear_Patch_3<R> &bp)
{
    switch(IO::get_mode(os)) {
    case IO::ASCII :
        return os << bp[0] << ' ' << bp[1] << ' ' << bp[2] << ' ' << bp[3];
    case IO::BINARY :
        return os << bp[0]  << bp[1]  << bp[2] << bp[3];
    default:
        os << "Bilinear_Patch_3(" << bp[0] <<  ", " << bp[1] <<   ", " << bp[2] <<   ", " << bp[3] <<")";
        return os;
    }
}

template < class R >
std::istream &
operator>>(std::istream &is, Bilinear_Patch_3<R> &bp)
{
    typename R::Point_3 p, q, r, s;

    is >> p >> q >> r >> s;

    if (is)
        bp = Bilinear_Patch_3<R>(p, q, r, s);
    return is;
}

} //namespace CGAL

#endif // CGAL_Bilinear_Patch_3_H
