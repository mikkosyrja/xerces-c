/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log$
 * Revision 1.1  2002/02/01 22:22:40  peiyongz
 * Initial revision
 *
 * Revision 1.7  2001/06/20 17:56:56  peiyongz
 * support for "fixed" option on constrainning facets
 *
 * Revision 1.6  2001/05/11 21:51:09  knoaman
 * Schema updates and fixes.
 *
 * Revision 1.5  2001/05/11 13:27:27  tng
 * Copyright update.
 *
 * Revision 1.4  2001/05/09 18:43:38  tng
 * Add StringDatatypeValidator and BooleanDatatypeValidator.  By Pei Yong Zhang.
 *
 * Revision 1.3  2001/05/03 21:09:52  tng
 * Schema: DatatypeValidator Update.  By Pei Yong Zhang.
 *
 * Revision 1.2  2001/05/03 19:17:43  knoaman
 * TraverseSchema Part II.
 *
 * Revision 1.1  2001/03/21 21:39:13  knoaman
 * Schema symbols and Datatype validator part I
 *
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/validators/schema/SchemaSymbols.hpp>

// ---------------------------------------------------------------------------
//  DatatypeValidator: Constructors and Destructor
// ---------------------------------------------------------------------------
DatatypeValidator::DatatypeValidator(DatatypeValidator* const baseValidator,
                                     RefHashTableOf<KVStringPair>* const facets,
                                     const int finalSet,
                                     const ValidatorType type)
    : fFinalSet(finalSet)
    , fFacetsDefined(0)
    , fFixed(0)
    , fType(type)
    , fBaseValidator(baseValidator)
    , fFacets(facets)
    , fPattern(0)
    , fRegex(0)
{
}

DatatypeValidator::~DatatypeValidator()
{
	cleanUp();
}

const XMLCh* DatatypeValidator::getWSstring(const short theType) const
{
    switch (theType)
    {
    case PRESERVE:
         return SchemaSymbols::fgWS_PRESERVE;
    case REPLACE:
         return SchemaSymbols::fgWS_COLLAPSE;
    case COLLAPSE:
         return SchemaSymbols::fgWS_REPLACE;
    default: 
         return SchemaSymbols::fgWS_PRESERVE;
    }

}
/**
  * End of file DatatypeValidator.cpp
  */

