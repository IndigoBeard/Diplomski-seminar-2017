/*************************************************************************
Copyright (c) Sergey Bochkanov (ALGLIB project).

>>> SOURCE LICENSE >>>
This  program  is  a  Commercial Edition  of the ALGLIB package  licensed
to Fakultet strojarstva i brodogradnje (Licensee).

Only  Licensee  and  its  Sublicensees  can  use/distribute  it according
to  the  ALGLIB  License  Agreement (see  below) between  Licensor  (Sole
Proprietor Bochkanov Sergey Anatolyevich) and Licensee.

All  developers  working  for  Licensee  should  register  themselves  at
alglib.net. Quick access link for Licensee's account can be found at  the
section 9 of scanned copy of ALGLIB License Agreement or in e-mails  from
ALGLIB Project.

This  source  code  may  contain  modifications  made  by   Licensee   or
Sublicensees  which  fall under the terms of the ALGLIB License Agreement
too.

================ ALGLIB LICENSE AGREEMENT ( APPENDIX A ) ================

DEFINITIONS:
* "ALGLIB" – software delivered by Licensor  to  Licensee  under  present
  Agreement. ALGLIB may include  Binary  Components  (delivered  only  in
  binary form) and Source  Code  Components  (with  optional  precompiled
  binary form).
  ALGLIB  may  include  optional  third-party  components, which may have
  their own licensing terms. Specific list of components  and  additional
  licensing terms (if there are any) is included in the license.txt  file
  in the root of archive containing ALGLIB. If you  decide  not  to  link
  ALGLIB with these optional components, their  licensing  terms  do  not
  apply to you.
* "Application"  -  program  developed  by  Licensee  (either  standalone
  application or software development library) which includes  ALGLIB  as
  one of its parts .
* "Sublicensee"  -  any  party  (including  resellers)   which   receives
  Application from Licensee or another Sublicensee.
* "Application License Agreement"  -  agreement  which   governs   usage/
  redistribution of the Application.
  
LICENSE GRANT:
Subject to the License Restrictions below, Licensor  grants  to  Licensee
the following non-exclusive royalty-free licenses:
A. To modify Source Code Components of ALGLIB and to use modified version
   on the terms of this Agreement.
B. To  develop  Applications  which  use  ALGLIB  and  to distribute such
   Applications in Binary and/or Source Code forms,  with  ALGLIB  either
   statically or dynamically linked. This right is granted provided that:
   * distribution of Source Code forms of Application/ALGLIB is performed
     subject to additional conditions set by clause H (this clause is not
     applied to binary-only distribution)
   * such Applications add significant  primary  functionality  different
     from that of the ALGLIB.
   * such Applications do not expose ALGLIB API (application  programming
     interface) either directly or indirectly
   * Sublicensee  has  no   right   to  use  ALGLIB  except  as  part  of
     the Application
   * any  subsequent  redistribution   respects    conditions    of   the
     present Agreement
   * all developers working for Licensee  should  register  at  company's
     account at www.alglib.net (in order to find login link, see  section
     9 of scanned copy of ALGLIB License Agreement -or find it in e-mails
     from ALGLIB Project).
C. To use Resellers for distribution of the  Application  (in  Binary  or
   Source Code forms), provided that the only activity Reseller  performs
   with Application is redistribution.
   
LICENSE RESTRICTIONS:
D. Licensee/Sublicensee may NOT use, copy or distribute ALGLIB except  as
   provided in this Agreement.
D2. Licensee/Sublicensee may NOT rent or lease ALGLIB to any third party.
E. Licensee/Sublicensee may NOT disassemble, reverse engineer, decompile,
   modify Binary Components of ALGLIB or compiled forms  of  Source  Code
   components.
F. Licensee/Sublicensee  may  NOT  remove  any  copyright notice from the
   Source Code / Binary Components.
G. Licensee/Sublicensee may NOT  disable/remove  code  which  checks  for
   presence of license keys (if such code is included in ALGLIB) from the
   Source Code / Binary Components.
H. Distribution of  Source  Code  forms  of  Application/ALGLIB  must  be
   performed subject to additional conditions:
   * Source Code Components of ALGLIB are distributed only as part of the
     Application. They are not  publicly  distributed.  Sublicensee  must
     explicitly accept Application License Agreement in order  to  access
     ALGLIB source code.
   * Sublicensee has no right to redistribute Application/ALGLIB (in  any
     form, Binary or Source Code), unless Sublicensee is Reseller who  is
     fully compliant with conditions set by clause C.
   * Sublicensee has no right to modify ALGLIB Source  Code,  except  for
     the purpose of fixing bugs
   * Sublicensee has no right to workaround "use ALGLIB only as  part  of
     the Application" limitation by sequentially modifying Application in
     a way which effectively creates new program with different  purpose.
     Application   License  Agreement  may  (a)  explicitly  forbid  such
     modifications, or (b) allow only limited set of "safe" modifications
     (developing plugins, fixing bugs, modifying only specific  parts  of
     the Application).
     
COPYRIGHT:
Title to the ALGLIB and all copies  thereof  remain  with  Licensor.  The
ALGLIB is copyrighted and is protected  by  Russian  copyright  laws  and
international treaty provisions. You will not remove any copyright notice
from the ALGLIB files. You agree to prevent any unauthorized  copying  of
the ALGLIB. Except as expressly provided herein, Licensor does not  grant
any express or implied right to you under Licensor  patents,  copyrights,
trademarks, or trade secret information.
>>> END OF LICENSE >>>
*************************************************************************/
#ifndef _alglibmisc_pkg_h
#define _alglibmisc_pkg_h
#include "ap.h"
#include "alglibinternal.h"

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS COMPUTATIONAL CORE DECLARATIONS (DATATYPES)
//
/////////////////////////////////////////////////////////////////////////
namespace alglib_impl
{
typedef struct
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t magicv;
} hqrndstate;
typedef struct
{
    ae_int_t n;
    ae_int_t nx;
    ae_int_t ny;
    ae_int_t normtype;
    ae_matrix xy;
    ae_vector tags;
    ae_vector boxmin;
    ae_vector boxmax;
    ae_vector nodes;
    ae_vector splits;
    ae_vector x;
    ae_int_t kneeded;
    double rneeded;
    ae_bool selfmatch;
    double approxf;
    ae_int_t kcur;
    ae_vector idx;
    ae_vector r;
    ae_vector buf;
    ae_vector curboxmin;
    ae_vector curboxmax;
    double curdist;
    ae_int_t debugcounter;
} kdtree;

}

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS C++ INTERFACE
//
/////////////////////////////////////////////////////////////////////////
namespace alglib
{

/*************************************************************************
Portable high quality random number generator state.
Initialized with HQRNDRandomize() or HQRNDSeed().

Fields:
    S1, S2      -   seed values
    V           -   precomputed value
    MagicV      -   'magic' value used to determine whether State structure
                    was correctly initialized.
*************************************************************************/
class _hqrndstate_owner
{
public:
    _hqrndstate_owner();
    _hqrndstate_owner(const _hqrndstate_owner &rhs);
    _hqrndstate_owner& operator=(const _hqrndstate_owner &rhs);
    virtual ~_hqrndstate_owner();
    alglib_impl::hqrndstate* c_ptr();
    alglib_impl::hqrndstate* c_ptr() const;
protected:
    alglib_impl::hqrndstate *p_struct;
};
class hqrndstate : public _hqrndstate_owner
{
public:
    hqrndstate();
    hqrndstate(const hqrndstate &rhs);
    hqrndstate& operator=(const hqrndstate &rhs);
    virtual ~hqrndstate();

};

/*************************************************************************

*************************************************************************/
class _kdtree_owner
{
public:
    _kdtree_owner();
    _kdtree_owner(const _kdtree_owner &rhs);
    _kdtree_owner& operator=(const _kdtree_owner &rhs);
    virtual ~_kdtree_owner();
    alglib_impl::kdtree* c_ptr();
    alglib_impl::kdtree* c_ptr() const;
protected:
    alglib_impl::kdtree *p_struct;
};
class kdtree : public _kdtree_owner
{
public:
    kdtree();
    kdtree(const kdtree &rhs);
    kdtree& operator=(const kdtree &rhs);
    virtual ~kdtree();

};

/*************************************************************************
HQRNDState  initialization  with  random  values  which come from standard
RNG.

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
void hqrndrandomize(hqrndstate &state);


/*************************************************************************
HQRNDState initialization with seed values

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
void hqrndseed(const ae_int_t s1, const ae_int_t s2, hqrndstate &state);


/*************************************************************************
This function generates random real number in (0,1),
not including interval boundaries

State structure must be initialized with HQRNDRandomize() or HQRNDSeed().

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
double hqrnduniformr(const hqrndstate &state);


/*************************************************************************
This function generates random integer number in [0, N)

1. State structure must be initialized with HQRNDRandomize() or HQRNDSeed()
2. N can be any positive number except for very large numbers:
   * close to 2^31 on 32-bit systems
   * close to 2^62 on 64-bit systems
   An exception will be generated if N is too large.

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
ae_int_t hqrnduniformi(const hqrndstate &state, const ae_int_t n);


/*************************************************************************
Random number generator: normal numbers

This function generates one random number from normal distribution.
Its performance is equal to that of HQRNDNormal2()

State structure must be initialized with HQRNDRandomize() or HQRNDSeed().

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
double hqrndnormal(const hqrndstate &state);


/*************************************************************************
Random number generator: random X and Y such that X^2+Y^2=1

State structure must be initialized with HQRNDRandomize() or HQRNDSeed().

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
void hqrndunit2(const hqrndstate &state, double &x, double &y);


/*************************************************************************
Random number generator: normal numbers

This function generates two independent random numbers from normal
distribution. Its performance is equal to that of HQRNDNormal()

State structure must be initialized with HQRNDRandomize() or HQRNDSeed().

  -- ALGLIB --
     Copyright 02.12.2009 by Bochkanov Sergey
*************************************************************************/
void hqrndnormal2(const hqrndstate &state, double &x1, double &x2);


/*************************************************************************
Random number generator: exponential distribution

State structure must be initialized with HQRNDRandomize() or HQRNDSeed().

  -- ALGLIB --
     Copyright 11.08.2007 by Bochkanov Sergey
*************************************************************************/
double hqrndexponential(const hqrndstate &state, const double lambdav);


/*************************************************************************
This function generates  random number from discrete distribution given by
finite sample X.

INPUT PARAMETERS
    State   -   high quality random number generator, must be
                initialized with HQRNDRandomize() or HQRNDSeed().
        X   -   finite sample
        N   -   number of elements to use, N>=1

RESULT
    this function returns one of the X[i] for random i=0..N-1

  -- ALGLIB --
     Copyright 08.11.2011 by Bochkanov Sergey
*************************************************************************/
double hqrnddiscrete(const hqrndstate &state, const real_1d_array &x, const ae_int_t n);


/*************************************************************************
This function generates random number from continuous  distribution  given
by finite sample X.

INPUT PARAMETERS
    State   -   high quality random number generator, must be
                initialized with HQRNDRandomize() or HQRNDSeed().
        X   -   finite sample, array[N] (can be larger, in this  case only
                leading N elements are used). THIS ARRAY MUST BE SORTED BY
                ASCENDING.
        N   -   number of elements to use, N>=1

RESULT
    this function returns random number from continuous distribution which
    tries to approximate X as mush as possible. min(X)<=Result<=max(X).

  -- ALGLIB --
     Copyright 08.11.2011 by Bochkanov Sergey
*************************************************************************/
double hqrndcontinuous(const hqrndstate &state, const real_1d_array &x, const ae_int_t n);

/*************************************************************************
This function serializes data structure to string.

Important properties of s_out:
* it contains alphanumeric characters, dots, underscores, minus signs
* these symbols are grouped into words, which are separated by spaces
  and Windows-style (CR+LF) newlines
* although  serializer  uses  spaces and CR+LF as separators, you can 
  replace any separator character by arbitrary combination of spaces,
  tabs, Windows or Unix newlines. It allows flexible reformatting  of
  the  string  in  case you want to include it into text or XML file. 
  But you should not insert separators into the middle of the "words"
  nor you should change case of letters.
* s_out can be freely moved between 32-bit and 64-bit systems, little
  and big endian machines, and so on. You can serialize structure  on
  32-bit machine and unserialize it on 64-bit one (or vice versa), or
  serialize  it  on  SPARC  and  unserialize  on  x86.  You  can also 
  serialize  it  in  C++ version of ALGLIB and unserialize in C# one, 
  and vice versa.
*************************************************************************/
void kdtreeserialize(kdtree &obj, std::string &s_out);


/*************************************************************************
This function unserializes data structure from string.
*************************************************************************/
void kdtreeunserialize(std::string &s_in, kdtree &obj);


/*************************************************************************
KD-tree creation

This subroutine creates KD-tree from set of X-values and optional Y-values

INPUT PARAMETERS
    XY      -   dataset, array[0..N-1,0..NX+NY-1].
                one row corresponds to one point.
                first NX columns contain X-values, next NY (NY may be zero)
                columns may contain associated Y-values
    N       -   number of points, N>=0.
    NX      -   space dimension, NX>=1.
    NY      -   number of optional Y-values, NY>=0.
    NormType-   norm type:
                * 0 denotes infinity-norm
                * 1 denotes 1-norm
                * 2 denotes 2-norm (Euclidean norm)

OUTPUT PARAMETERS
    KDT     -   KD-tree


NOTES

1. KD-tree  creation  have O(N*logN) complexity and O(N*(2*NX+NY))  memory
   requirements.
2. Although KD-trees may be used with any combination of N  and  NX,  they
   are more efficient than brute-force search only when N >> 4^NX. So they
   are most useful in low-dimensional tasks (NX=2, NX=3). NX=1  is another
   inefficient case, because  simple  binary  search  (without  additional
   structures) is much more efficient in such tasks than KD-trees.

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreebuild(const real_2d_array &xy, const ae_int_t n, const ae_int_t nx, const ae_int_t ny, const ae_int_t normtype, kdtree &kdt);
void kdtreebuild(const real_2d_array &xy, const ae_int_t nx, const ae_int_t ny, const ae_int_t normtype, kdtree &kdt);


/*************************************************************************
KD-tree creation

This  subroutine  creates  KD-tree  from set of X-values, integer tags and
optional Y-values

INPUT PARAMETERS
    XY      -   dataset, array[0..N-1,0..NX+NY-1].
                one row corresponds to one point.
                first NX columns contain X-values, next NY (NY may be zero)
                columns may contain associated Y-values
    Tags    -   tags, array[0..N-1], contains integer tags associated
                with points.
    N       -   number of points, N>=0
    NX      -   space dimension, NX>=1.
    NY      -   number of optional Y-values, NY>=0.
    NormType-   norm type:
                * 0 denotes infinity-norm
                * 1 denotes 1-norm
                * 2 denotes 2-norm (Euclidean norm)

OUTPUT PARAMETERS
    KDT     -   KD-tree

NOTES

1. KD-tree  creation  have O(N*logN) complexity and O(N*(2*NX+NY))  memory
   requirements.
2. Although KD-trees may be used with any combination of N  and  NX,  they
   are more efficient than brute-force search only when N >> 4^NX. So they
   are most useful in low-dimensional tasks (NX=2, NX=3). NX=1  is another
   inefficient case, because  simple  binary  search  (without  additional
   structures) is much more efficient in such tasks than KD-trees.

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreebuildtagged(const real_2d_array &xy, const integer_1d_array &tags, const ae_int_t n, const ae_int_t nx, const ae_int_t ny, const ae_int_t normtype, kdtree &kdt);
void kdtreebuildtagged(const real_2d_array &xy, const integer_1d_array &tags, const ae_int_t nx, const ae_int_t ny, const ae_int_t normtype, kdtree &kdt);


/*************************************************************************
K-NN query: K nearest neighbors

INPUT PARAMETERS
    KDT         -   KD-tree
    X           -   point, array[0..NX-1].
    K           -   number of neighbors to return, K>=1
    SelfMatch   -   whether self-matches are allowed:
                    * if True, nearest neighbor may be the point itself
                      (if it exists in original dataset)
                    * if False, then only points with non-zero distance
                      are returned
                    * if not given, considered True

RESULT
    number of actual neighbors found (either K or N, if K>N).

This  subroutine  performs  query  and  stores  its result in the internal
structures of the KD-tree. You can use  following  subroutines  to  obtain
these results:
* KDTreeQueryResultsX() to get X-values
* KDTreeQueryResultsXY() to get X- and Y-values
* KDTreeQueryResultsTags() to get tag values
* KDTreeQueryResultsDistances() to get distances

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
ae_int_t kdtreequeryknn(const kdtree &kdt, const real_1d_array &x, const ae_int_t k, const bool selfmatch);
ae_int_t kdtreequeryknn(const kdtree &kdt, const real_1d_array &x, const ae_int_t k);


/*************************************************************************
R-NN query: all points within R-sphere centered at X

INPUT PARAMETERS
    KDT         -   KD-tree
    X           -   point, array[0..NX-1].
    R           -   radius of sphere (in corresponding norm), R>0
    SelfMatch   -   whether self-matches are allowed:
                    * if True, nearest neighbor may be the point itself
                      (if it exists in original dataset)
                    * if False, then only points with non-zero distance
                      are returned
                    * if not given, considered True

RESULT
    number of neighbors found, >=0

This  subroutine  performs  query  and  stores  its result in the internal
structures of the KD-tree. You can use  following  subroutines  to  obtain
actual results:
* KDTreeQueryResultsX() to get X-values
* KDTreeQueryResultsXY() to get X- and Y-values
* KDTreeQueryResultsTags() to get tag values
* KDTreeQueryResultsDistances() to get distances

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
ae_int_t kdtreequeryrnn(const kdtree &kdt, const real_1d_array &x, const double r, const bool selfmatch);
ae_int_t kdtreequeryrnn(const kdtree &kdt, const real_1d_array &x, const double r);


/*************************************************************************
K-NN query: approximate K nearest neighbors

INPUT PARAMETERS
    KDT         -   KD-tree
    X           -   point, array[0..NX-1].
    K           -   number of neighbors to return, K>=1
    SelfMatch   -   whether self-matches are allowed:
                    * if True, nearest neighbor may be the point itself
                      (if it exists in original dataset)
                    * if False, then only points with non-zero distance
                      are returned
                    * if not given, considered True
    Eps         -   approximation factor, Eps>=0. eps-approximate  nearest
                    neighbor  is  a  neighbor  whose distance from X is at
                    most (1+eps) times distance of true nearest neighbor.

RESULT
    number of actual neighbors found (either K or N, if K>N).

NOTES
    significant performance gain may be achieved only when Eps  is  is  on
    the order of magnitude of 1 or larger.

This  subroutine  performs  query  and  stores  its result in the internal
structures of the KD-tree. You can use  following  subroutines  to  obtain
these results:
* KDTreeQueryResultsX() to get X-values
* KDTreeQueryResultsXY() to get X- and Y-values
* KDTreeQueryResultsTags() to get tag values
* KDTreeQueryResultsDistances() to get distances

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
ae_int_t kdtreequeryaknn(const kdtree &kdt, const real_1d_array &x, const ae_int_t k, const bool selfmatch, const double eps);
ae_int_t kdtreequeryaknn(const kdtree &kdt, const real_1d_array &x, const ae_int_t k, const double eps);


/*************************************************************************
X-values from last query

INPUT PARAMETERS
    KDT     -   KD-tree
    X       -   possibly pre-allocated buffer. If X is too small to store
                result, it is resized. If size(X) is enough to store
                result, it is left unchanged.

OUTPUT PARAMETERS
    X       -   rows are filled with X-values

NOTES
1. points are ordered by distance from the query point (first = closest)
2. if  XY is larger than required to store result, only leading part  will
   be overwritten; trailing part will be left unchanged. So  if  on  input
   XY = [[A,B],[C,D]], and result is [1,2],  then  on  exit  we  will  get
   XY = [[1,2],[C,D]]. This is done purposely to increase performance;  if
   you want function  to  resize  array  according  to  result  size,  use
   function with same name and suffix 'I'.

SEE ALSO
* KDTreeQueryResultsXY()            X- and Y-values
* KDTreeQueryResultsTags()          tag values
* KDTreeQueryResultsDistances()     distances

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultsx(const kdtree &kdt, real_2d_array &x);


/*************************************************************************
X- and Y-values from last query

INPUT PARAMETERS
    KDT     -   KD-tree
    XY      -   possibly pre-allocated buffer. If XY is too small to store
                result, it is resized. If size(XY) is enough to store
                result, it is left unchanged.

OUTPUT PARAMETERS
    XY      -   rows are filled with points: first NX columns with
                X-values, next NY columns - with Y-values.

NOTES
1. points are ordered by distance from the query point (first = closest)
2. if  XY is larger than required to store result, only leading part  will
   be overwritten; trailing part will be left unchanged. So  if  on  input
   XY = [[A,B],[C,D]], and result is [1,2],  then  on  exit  we  will  get
   XY = [[1,2],[C,D]]. This is done purposely to increase performance;  if
   you want function  to  resize  array  according  to  result  size,  use
   function with same name and suffix 'I'.

SEE ALSO
* KDTreeQueryResultsX()             X-values
* KDTreeQueryResultsTags()          tag values
* KDTreeQueryResultsDistances()     distances

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultsxy(const kdtree &kdt, real_2d_array &xy);


/*************************************************************************
Tags from last query

INPUT PARAMETERS
    KDT     -   KD-tree
    Tags    -   possibly pre-allocated buffer. If X is too small to store
                result, it is resized. If size(X) is enough to store
                result, it is left unchanged.

OUTPUT PARAMETERS
    Tags    -   filled with tags associated with points,
                or, when no tags were supplied, with zeros

NOTES
1. points are ordered by distance from the query point (first = closest)
2. if  XY is larger than required to store result, only leading part  will
   be overwritten; trailing part will be left unchanged. So  if  on  input
   XY = [[A,B],[C,D]], and result is [1,2],  then  on  exit  we  will  get
   XY = [[1,2],[C,D]]. This is done purposely to increase performance;  if
   you want function  to  resize  array  according  to  result  size,  use
   function with same name and suffix 'I'.

SEE ALSO
* KDTreeQueryResultsX()             X-values
* KDTreeQueryResultsXY()            X- and Y-values
* KDTreeQueryResultsDistances()     distances

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultstags(const kdtree &kdt, integer_1d_array &tags);


/*************************************************************************
Distances from last query

INPUT PARAMETERS
    KDT     -   KD-tree
    R       -   possibly pre-allocated buffer. If X is too small to store
                result, it is resized. If size(X) is enough to store
                result, it is left unchanged.

OUTPUT PARAMETERS
    R       -   filled with distances (in corresponding norm)

NOTES
1. points are ordered by distance from the query point (first = closest)
2. if  XY is larger than required to store result, only leading part  will
   be overwritten; trailing part will be left unchanged. So  if  on  input
   XY = [[A,B],[C,D]], and result is [1,2],  then  on  exit  we  will  get
   XY = [[1,2],[C,D]]. This is done purposely to increase performance;  if
   you want function  to  resize  array  according  to  result  size,  use
   function with same name and suffix 'I'.

SEE ALSO
* KDTreeQueryResultsX()             X-values
* KDTreeQueryResultsXY()            X- and Y-values
* KDTreeQueryResultsTags()          tag values

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultsdistances(const kdtree &kdt, real_1d_array &r);


/*************************************************************************
X-values from last query; 'interactive' variant for languages like  Python
which   support    constructs   like  "X = KDTreeQueryResultsXI(KDT)"  and
interactive mode of interpreter.

This function allocates new array on each call,  so  it  is  significantly
slower than its 'non-interactive' counterpart, but it is  more  convenient
when you call it from command line.

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultsxi(const kdtree &kdt, real_2d_array &x);


/*************************************************************************
XY-values from last query; 'interactive' variant for languages like Python
which   support    constructs   like "XY = KDTreeQueryResultsXYI(KDT)" and
interactive mode of interpreter.

This function allocates new array on each call,  so  it  is  significantly
slower than its 'non-interactive' counterpart, but it is  more  convenient
when you call it from command line.

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultsxyi(const kdtree &kdt, real_2d_array &xy);


/*************************************************************************
Tags  from  last  query;  'interactive' variant for languages like  Python
which  support  constructs  like "Tags = KDTreeQueryResultsTagsI(KDT)" and
interactive mode of interpreter.

This function allocates new array on each call,  so  it  is  significantly
slower than its 'non-interactive' counterpart, but it is  more  convenient
when you call it from command line.

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultstagsi(const kdtree &kdt, integer_1d_array &tags);


/*************************************************************************
Distances from last query; 'interactive' variant for languages like Python
which  support  constructs   like  "R = KDTreeQueryResultsDistancesI(KDT)"
and interactive mode of interpreter.

This function allocates new array on each call,  so  it  is  significantly
slower than its 'non-interactive' counterpart, but it is  more  convenient
when you call it from command line.

  -- ALGLIB --
     Copyright 28.02.2010 by Bochkanov Sergey
*************************************************************************/
void kdtreequeryresultsdistancesi(const kdtree &kdt, real_1d_array &r);

/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Counts number of True values in the boolean 1D array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
ae_int_t xdebugb1count(const boolean_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by NOT(a[i]).
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugb1not(const boolean_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Appends copy of array to itself.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugb1appendcopy(boolean_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate N-element array with even-numbered elements set to True.
Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugb1outeven(const ae_int_t n, boolean_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of elements in the array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
ae_int_t xdebugi1sum(const integer_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by -A[I]
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugi1neg(const integer_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Appends copy of array to itself.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugi1appendcopy(integer_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate N-element array with even-numbered A[I] set to I, and odd-numbered
ones set to 0.

Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugi1outeven(const ae_int_t n, integer_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of elements in the array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
double xdebugr1sum(const real_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by -A[I]
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugr1neg(const real_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Appends copy of array to itself.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugr1appendcopy(real_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate N-element array with even-numbered A[I] set to I*0.25,
and odd-numbered ones are set to 0.

Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugr1outeven(const ae_int_t n, real_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of elements in the array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
alglib::complex xdebugc1sum(const complex_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by -A[I]
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugc1neg(const complex_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Appends copy of array to itself.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugc1appendcopy(complex_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate N-element array with even-numbered A[K] set to (x,y) = (K*0.25, K*0.125)
and odd-numbered ones are set to 0.

Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugc1outeven(const ae_int_t n, complex_1d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Counts number of True values in the boolean 2D array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
ae_int_t xdebugb2count(const boolean_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by NOT(a[i]).
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugb2not(const boolean_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Transposes array.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugb2transpose(boolean_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate MxN matrix with elements set to "Sin(3*I+5*J)>0"
Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugb2outsin(const ae_int_t m, const ae_int_t n, boolean_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of elements in the array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
ae_int_t xdebugi2sum(const integer_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by -a[i,j]
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugi2neg(const integer_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Transposes array.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugi2transpose(integer_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate MxN matrix with elements set to "Sign(Sin(3*I+5*J))"
Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugi2outsin(const ae_int_t m, const ae_int_t n, integer_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of elements in the array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
double xdebugr2sum(const real_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by -a[i,j]
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugr2neg(const real_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Transposes array.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugr2transpose(real_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate MxN matrix with elements set to "Sin(3*I+5*J)"
Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugr2outsin(const ae_int_t m, const ae_int_t n, real_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of elements in the array.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
alglib::complex xdebugc2sum(const complex_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Replace all values in array by -a[i,j]
Array is passed using "shared" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugc2neg(const complex_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Transposes array.
Array is passed using "var" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugc2transpose(complex_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Generate MxN matrix with elements set to "Sin(3*I+5*J),Cos(3*I+5*J)"
Array is passed using "out" convention.

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
void xdebugc2outsincos(const ae_int_t m, const ae_int_t n, complex_2d_array &a);


/*************************************************************************
This is debug function intended for testing ALGLIB interface generator.
Never use it in any real life project.

Returns sum of a[i,j]*(1+b[i,j]) such that c[i,j] is True

  -- ALGLIB --
     Copyright 11.10.2013 by Bochkanov Sergey
*************************************************************************/
double xdebugmaskedbiasedproductsum(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const real_2d_array &b, const boolean_2d_array &c);
}

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS COMPUTATIONAL CORE DECLARATIONS (FUNCTIONS)
//
/////////////////////////////////////////////////////////////////////////
namespace alglib_impl
{
void hqrndrandomize(hqrndstate* state, ae_state *_state);
void hqrndseed(ae_int_t s1,
     ae_int_t s2,
     hqrndstate* state,
     ae_state *_state);
double hqrnduniformr(hqrndstate* state, ae_state *_state);
ae_int_t hqrnduniformi(hqrndstate* state, ae_int_t n, ae_state *_state);
double hqrndnormal(hqrndstate* state, ae_state *_state);
void hqrndunit2(hqrndstate* state, double* x, double* y, ae_state *_state);
void hqrndnormal2(hqrndstate* state,
     double* x1,
     double* x2,
     ae_state *_state);
double hqrndexponential(hqrndstate* state,
     double lambdav,
     ae_state *_state);
double hqrnddiscrete(hqrndstate* state,
     /* Real    */ ae_vector* x,
     ae_int_t n,
     ae_state *_state);
double hqrndcontinuous(hqrndstate* state,
     /* Real    */ ae_vector* x,
     ae_int_t n,
     ae_state *_state);
ae_bool _hqrndstate_init(void* _p, ae_state *_state, ae_bool make_automatic);
ae_bool _hqrndstate_init_copy(void* _dst, void* _src, ae_state *_state, ae_bool make_automatic);
void _hqrndstate_clear(void* _p);
void _hqrndstate_destroy(void* _p);
void kdtreebuild(/* Real    */ ae_matrix* xy,
     ae_int_t n,
     ae_int_t nx,
     ae_int_t ny,
     ae_int_t normtype,
     kdtree* kdt,
     ae_state *_state);
void kdtreebuildtagged(/* Real    */ ae_matrix* xy,
     /* Integer */ ae_vector* tags,
     ae_int_t n,
     ae_int_t nx,
     ae_int_t ny,
     ae_int_t normtype,
     kdtree* kdt,
     ae_state *_state);
ae_int_t kdtreequeryknn(kdtree* kdt,
     /* Real    */ ae_vector* x,
     ae_int_t k,
     ae_bool selfmatch,
     ae_state *_state);
ae_int_t kdtreequeryrnn(kdtree* kdt,
     /* Real    */ ae_vector* x,
     double r,
     ae_bool selfmatch,
     ae_state *_state);
ae_int_t kdtreequeryaknn(kdtree* kdt,
     /* Real    */ ae_vector* x,
     ae_int_t k,
     ae_bool selfmatch,
     double eps,
     ae_state *_state);
void kdtreequeryresultsx(kdtree* kdt,
     /* Real    */ ae_matrix* x,
     ae_state *_state);
void kdtreequeryresultsxy(kdtree* kdt,
     /* Real    */ ae_matrix* xy,
     ae_state *_state);
void kdtreequeryresultstags(kdtree* kdt,
     /* Integer */ ae_vector* tags,
     ae_state *_state);
void kdtreequeryresultsdistances(kdtree* kdt,
     /* Real    */ ae_vector* r,
     ae_state *_state);
void kdtreequeryresultsxi(kdtree* kdt,
     /* Real    */ ae_matrix* x,
     ae_state *_state);
void kdtreequeryresultsxyi(kdtree* kdt,
     /* Real    */ ae_matrix* xy,
     ae_state *_state);
void kdtreequeryresultstagsi(kdtree* kdt,
     /* Integer */ ae_vector* tags,
     ae_state *_state);
void kdtreequeryresultsdistancesi(kdtree* kdt,
     /* Real    */ ae_vector* r,
     ae_state *_state);
void kdtreealloc(ae_serializer* s, kdtree* tree, ae_state *_state);
void kdtreeserialize(ae_serializer* s, kdtree* tree, ae_state *_state);
void kdtreeunserialize(ae_serializer* s, kdtree* tree, ae_state *_state);
ae_bool _kdtree_init(void* _p, ae_state *_state, ae_bool make_automatic);
ae_bool _kdtree_init_copy(void* _dst, void* _src, ae_state *_state, ae_bool make_automatic);
void _kdtree_clear(void* _p);
void _kdtree_destroy(void* _p);
ae_int_t xdebugb1count(/* Boolean */ ae_vector* a, ae_state *_state);
void xdebugb1not(/* Boolean */ ae_vector* a, ae_state *_state);
void xdebugb1appendcopy(/* Boolean */ ae_vector* a, ae_state *_state);
void xdebugb1outeven(ae_int_t n,
     /* Boolean */ ae_vector* a,
     ae_state *_state);
ae_int_t xdebugi1sum(/* Integer */ ae_vector* a, ae_state *_state);
void xdebugi1neg(/* Integer */ ae_vector* a, ae_state *_state);
void xdebugi1appendcopy(/* Integer */ ae_vector* a, ae_state *_state);
void xdebugi1outeven(ae_int_t n,
     /* Integer */ ae_vector* a,
     ae_state *_state);
double xdebugr1sum(/* Real    */ ae_vector* a, ae_state *_state);
void xdebugr1neg(/* Real    */ ae_vector* a, ae_state *_state);
void xdebugr1appendcopy(/* Real    */ ae_vector* a, ae_state *_state);
void xdebugr1outeven(ae_int_t n,
     /* Real    */ ae_vector* a,
     ae_state *_state);
ae_complex xdebugc1sum(/* Complex */ ae_vector* a, ae_state *_state);
void xdebugc1neg(/* Complex */ ae_vector* a, ae_state *_state);
void xdebugc1appendcopy(/* Complex */ ae_vector* a, ae_state *_state);
void xdebugc1outeven(ae_int_t n,
     /* Complex */ ae_vector* a,
     ae_state *_state);
ae_int_t xdebugb2count(/* Boolean */ ae_matrix* a, ae_state *_state);
void xdebugb2not(/* Boolean */ ae_matrix* a, ae_state *_state);
void xdebugb2transpose(/* Boolean */ ae_matrix* a, ae_state *_state);
void xdebugb2outsin(ae_int_t m,
     ae_int_t n,
     /* Boolean */ ae_matrix* a,
     ae_state *_state);
ae_int_t xdebugi2sum(/* Integer */ ae_matrix* a, ae_state *_state);
void xdebugi2neg(/* Integer */ ae_matrix* a, ae_state *_state);
void xdebugi2transpose(/* Integer */ ae_matrix* a, ae_state *_state);
void xdebugi2outsin(ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_matrix* a,
     ae_state *_state);
double xdebugr2sum(/* Real    */ ae_matrix* a, ae_state *_state);
void xdebugr2neg(/* Real    */ ae_matrix* a, ae_state *_state);
void xdebugr2transpose(/* Real    */ ae_matrix* a, ae_state *_state);
void xdebugr2outsin(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_state *_state);
ae_complex xdebugc2sum(/* Complex */ ae_matrix* a, ae_state *_state);
void xdebugc2neg(/* Complex */ ae_matrix* a, ae_state *_state);
void xdebugc2transpose(/* Complex */ ae_matrix* a, ae_state *_state);
void xdebugc2outsincos(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_state *_state);
double xdebugmaskedbiasedproductsum(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     /* Real    */ ae_matrix* b,
     /* Boolean */ ae_matrix* c,
     ae_state *_state);

}
#endif

