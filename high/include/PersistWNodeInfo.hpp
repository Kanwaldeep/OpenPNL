#ifndef __PERSISTWNODEINFO_HPP__
#define __PERSISTWNODEINFO_HPP__

#include "pnlHighConf.hpp"
#include "pnlTok.hpp"
#include "pnl_dll.hpp"
//#include "pnlPersistence.hpp"

// FORWARDS

struct PNLHIGH_API WNodeInfo: public pnl::CPNLBase
{
    WNodeInfo(String &name, pnl::CNodeType nt);
    WNodeInfo() {}

    String m_Name;
    TokArr m_aValue;
    pnl::CNodeType m_NodeType;
};

class PNLHIGH_API PersistWNodeInfo: public pnl::CPersistence
{
public:
    virtual const char *Signature();
    virtual void Save(pnl::CPNLBase *pObj, pnl::CContextSave *pContext);
    virtual pnl::CPNLBase *Load(pnl::CContextLoad *pContext);
    virtual void TraverseSubobject(pnl::CPNLBase *pObj, pnl::CContext *pContext);
    virtual bool IsHandledType(pnl::CPNLBase *pObj) const;
};

class PNLHIGH_API PersistTokenArray: public pnl::CPersistence
{
public:
    virtual const char *Signature();
    virtual void Save(pnl::CPNLBase *pObj, pnl::CContextSave *pContext);
    virtual pnl::CPNLBase *Load(pnl::CContextLoad *pContext);
    virtual bool IsHandledType(pnl::CPNLBase *pObj) const;
};

#endif //__PERSISTWNODEINFO_HPP__