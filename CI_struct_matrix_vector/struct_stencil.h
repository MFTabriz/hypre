/*BHEADER**********************************************************************
 * (c) 1997   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/
/******************************************************************************
 *
 * Header info for hypre_StructStencil data structures
 *
 *****************************************************************************/

#ifndef hypre_STENCIL_HEADER
#define hypre_STENCIL_HEADER


/*--------------------------------------------------------------------------
 * hypre_StructStencil
 *--------------------------------------------------------------------------*/

typedef int hypre_StructStencilElt[3];

typedef struct
{
   hypre_StructStencilElt  *shape;   /* Description of a stencil's shape */
   int              size;    /* Number of stencil coefficients */

   int              dim;     /* Number of dimensions for the associated grid */

} hypre_StructStencil;

/*--------------------------------------------------------------------------
 * Accessor functions for the hypre_StructStencil structure
 *--------------------------------------------------------------------------*/

#define hypre_StructStencilShape(stencil) ((stencil) -> shape)
#define hypre_StructStencilSize(stencil)  ((stencil) -> size)

#define hypre_StructStencilDim(stencil)   ((stencil) -> dim)


#endif
