namespace CGAL {

/*!
\ingroup kernel_classes3

An object `bp` of the class `Bilinear_patch_3` is a surface created by 
sweeping a line segment linearly in each vertex. The surface is assumed 
to be in an ambient three-dimensional Euclidean space \f$ \E^3\f$. As the 
bilinear_patch is not a full-dimensional object there is only a test 
whether a point lies on the bilinear patch or not.

\cgalModels `Kernel::Bilinear_patch_3`

*/
template< typename Kernel >
class Bilinear_patch_3 {
public:

/// \name Creation
/// @{

/*!
introduces a bilinear_patch `bp` with vertices `p`, `q`, `r`, and `s`.
*/
Triangle_3(const Point_3<Kernel> &p,
const Point_3<Kernel> &q,
const Point_3<Kernel> &r,
const Point_3<Kernel> &s);

/// @}

/// \name Operations
/// @{

/*!
Test for equality: two bilinear patches `bp1` and `bp2` are equal, iff there
exists a cyclic permutation of the vertices of `bp1`, such that
they are equal to the vertices of `bp2`.
*/
bool operator==(const Triangle_3<Kernel> &t2) const;

/*!
Test for inequality.
*/
bool operator!=(const Triangle_3<Kernel> &t2) const;

/*!
returns the i'th vertex modulo 4 of `bp`.
*/
Point_3<Kernel> vertex(int i) const;

/*!
returns `vertex(int i)`.
*/
Point_3<Kernel> operator[](int i) const;

/// @}

/// \name Predicates
/// @{

/*!
`t` is degenerate if its vertices are collinear.
*/
bool is_degenerate() const;

/*!
A point is on `t`, if it is on a vertex, an edge or the
face of `t`.
*/
// bool has_on(const Point_3<Kernel> &p) const;

/// @}

/// \name Miscellaneous
/// @{

/*!
returns the Tetrahedron_3 object corresponding to the vertices 
of the bilinear patch.
*/
Tetrahedron_3<Kernel> tetrahedron() const;

/*!
returns the triangle obtained by applying `at` on the three
vertices of `t`.
*/
Bilinear_patch_3<Kernel> transform(const Aff_transformation_3<Kernel> &at) const;

/// @}

}; /* end Bilinear_patch_3 */
} /* end namespace CGAL */
