// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.10-p100  (32 bit), build 50398 Tue, 27 May 2014
// 
// File created on Sat Oct 11 22:26:53 2014
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
#ifndef dflipflop_ctos_wrapper_P
#define dflipflop_ctos_wrapper_P

#include <systemc.h>

#define CTOS_TARGET_SUFFIX(ARG) CTOS_TARGET_SUFFIX_TMP(ARG)
#define CTOS_TARGET_SUFFIX_TMP(ARG) "_" #ARG


// This foreign module encapsulates the CtoS generated Verilog models
class dflipflop_ctos_wrapper_vlog : public ncsc_foreign_module {
    SC_HAS_PROCESS(dflipflop_ctos_wrapper_vlog);
  public:
    dflipflop_ctos_wrapper_vlog(sc_module_name name, char  const *ctosModelSuffix)
    :   ncsc_foreign_module(name),
        din("din"),
        clk("clk"),
        reset("reset"),
        dout("dout"),
        m_hdlName("dflipflop")
    {
        m_hdlName+=ctosModelSuffix;
    }
    sc_in<sc_lv<1> >  din;
    sc_in<bool>  clk;
    sc_in<bool>  reset;
    sc_out<sc_lv<1> >  dout;
    std::string m_hdlName;
    char  const *hdl_name() const
    {
        return m_hdlName.c_str();
    }
};


// This is the main module for the verification wrapper
class dflipflop_ctos_wrapper : public sc_module {
    SC_HAS_PROCESS(dflipflop_ctos_wrapper);
  public:
    dflipflop_ctos_wrapper(sc_module_name name, char  const *ctosDutSuffix = "", char  const *ctosRefSuffix = NULL, bool compare = false)
    :   sc_module(name),
        din("din"),
        clk("clk"),
        reset("reset"),
        dout("dout"),
        m_enableCompare(true),
        din_vlog(NULL),
        dout_vlog_dut(NULL),
        dout_vlog_ref(NULL),
        dout_cpp("dout_cpp"),
        m_ctos_compare(compare)
    {
        m_ctos_dut_type=modelTypeLookUp(ctosDutSuffix);
        m_ctos_ref_type=modelTypeLookUp(ctosRefSuffix);
        if (m_ctos_dut_type==ORIG) {
            m_dut_cpp=new dflipflop("m_dut_cpp");
            m_dut_cpp->din(din);
            m_dut_cpp->clk(clk);
            m_dut_cpp->reset(reset);
            m_dut_cpp->dout(dout);
            std::cout << "CtoS Verification Wrapper: Instantiating module dflipflop as DUT" << std::endl;
        } else {
            m_dut_vlog=new dflipflop_ctos_wrapper_vlog("m_dut_vlog", ctosDutSuffix);
            din_vlog=new sc_signal<sc_lv<1> > ("din_vlog");
            m_dut_vlog->din(*din_vlog);
            m_dut_vlog->clk(clk);
            m_dut_vlog->reset(reset);
            dout_vlog_dut=new sc_signal<sc_lv<1> > ("dout_vlog_dut");
            m_dut_vlog->dout(*dout_vlog_dut);
            std::cout << "CtoS Verification Wrapper: Instantiating module " << m_dut_vlog->hdl_name() << " as DUT" << std::endl;
        }
        if (m_ctos_ref_type!=UNKNOWN) {
            if (m_ctos_ref_type==ORIG) {
                m_ref_cpp=new dflipflop("m_ref_cpp");
                m_ref_cpp->din(din);
                m_ref_cpp->clk(clk);
                m_ref_cpp->reset(reset);
                m_ref_cpp->dout(dout_cpp);
                std::cout << "CtoS Verification Wrapper: Instantiating module dflipflop as REF" << std::endl;
            } else {
                m_ref_vlog=new dflipflop_ctos_wrapper_vlog("m_ref_vlog", ctosRefSuffix);
                if (din_vlog==NULL) {
                    din_vlog=new sc_signal<sc_lv<1> > ("din_vlog");
                }
                m_ref_vlog->din(*din_vlog);
                m_ref_vlog->clk(clk);
                m_ref_vlog->reset(reset);
                if (dout_vlog_ref==NULL) {
                    dout_vlog_ref=new sc_signal<sc_lv<1> > ("dout_vlog_ref");
                }
                m_ref_vlog->dout(*dout_vlog_ref);
                std::cout << "CtoS Verification Wrapper: Instantiating module " << m_ref_vlog->hdl_name() << " as REF" << std::endl;
            }
        }
        if ((((unsigned int)m_ctos_dut_type)>1U)||((m_ctos_ref_type!=UNKNOWN)&&(((unsigned int)m_ctos_ref_type)>1U))) {
            SC_METHOD(ctos_convert_input);
            sensitive << din;
            if (dout_vlog_dut!=NULL) {
                SC_METHOD(ctos_convert_output);
                dont_initialize();
                sensitive << *dout_vlog_dut;
            }
        }
        if ((m_ctos_ref_type!=UNKNOWN)&&m_ctos_compare) {
            SC_METHOD(ctos_compare_outputs);
            dont_initialize();
            sensitive << clk.neg();
        }
    }
    sc_in<bool>  din;
    // clock clk period 20000 rise 0 fall 10000
    sc_in<bool>  clk;
    // reset reset true
    sc_in<bool>  reset;
    sc_out<bool>  dout;
    sc_event m_ctosWrapperError;
    bool m_enableCompare;
    
    enum SimulateRTLOnlyEnum {
        Unsupported = 0,
        SimulateRTLOnly = 1
    };

  private:
    
    enum ModelTypeEnum {
        ORIG = 0,
        VLOG = 2,
        UNKNOWN = 3
    };

    sc_signal<sc_lv<1> >  *din_vlog;
    sc_signal<sc_lv<1> >  *dout_vlog_dut;
    sc_signal<sc_lv<1> >  *dout_vlog_ref;
    sc_signal<bool>  dout_cpp;
    ModelTypeEnum m_ctos_dut_type;
    ModelTypeEnum m_ctos_ref_type;
    bool m_ctos_compare;
    
    union {
      public:
        dflipflop *m_ref_cpp;
        dflipflop_ctos_wrapper_vlog *m_ref_vlog;
    };

    
    union {
      public:
        dflipflop *m_dut_cpp;
        dflipflop_ctos_wrapper_vlog *m_dut_vlog;
    };

    // Converts input string to enumeration
    ModelTypeEnum modelTypeLookUp(char  const *str)
    {
        if (!str) {
            return UNKNOWN;
        }
        std::string inputString = str;
        if (inputString.empty()) {
            return ORIG;
        } else {
            return VLOG;
        }
    }
    
    template <class T, class U> 
    bool ctos_check_unknown_values(T  const *dutSig, U  const &refSig, std::string  const &dutName, std::string  const &refName)
    {
        if (!(dutSig->read().is_01())) {
            std::cout << sc_time_stamp()
            	      << ": ctos_check_unknown_values encountered unknown values!"
            	      << std::endl << dutName << ": " << (dutSig->read().to_string())
            	      << std::endl << refName << ": " << refSig << std::endl;
        }
        return true;
    }
    
    template <class T> 
    void ctos_compare_output_values(T  const &dutSig, T  const &refSig, std::string  const &dutName, std::string  const &refName)
    {
        if (!(dutSig==refSig)) {
            std::cout << sc_time_stamp()
            	      << ": ctos_compare_output_values mismatch!"
            	      << std::endl << dutName << ": " << dutSig
            	      << std::endl << refName << ": " << refSig << std::endl;
            m_ctosWrapperError.notify();
        }
    }
    void ctos_convert_input()
    {
        *din_vlog=sc_lv<1> ((din.read()));
    }
    void ctos_convert_output()
    {
        dout=dout_vlog_dut->read().to_uint();
    }
    void ctos_compare_outputs()
    {
        if ((reset.read()!=1U)&&m_enableCompare) {
            bool dout_ref;
            bool dout_dut;
            dout_dut=dout->read();
            if (m_ctos_ref_type==ORIG) {
                dout_ref=dout_cpp.read();
            } else {
                dout_ref=dout_vlog_ref->read().to_uint();
                ctos_check_unknown_values(dout_vlog_ref, dout_ref, "dout_vlog_ref", "dout_ref");
            }
            if (m_ctos_dut_type==VLOG) {
                ctos_check_unknown_values(dout_vlog_dut, dout_ref, "dout_vlog_dut", "dout_ref");
            }
            ctos_compare_output_values(dout_dut, dout_ref, "dout_dut", "dout_ref");
        }
    }
  public:
    // Use this constructor only if your CtoS verilog model has no suffix
    dflipflop_ctos_wrapper(sc_module_name name, SimulateRTLOnlyEnum simulateRTLOnly)
    :   sc_module(name),
        din("din"),
        clk("clk"),
        reset("reset"),
        dout("dout"),
        m_enableCompare(false),
        m_ctos_compare(false)
    {
        m_ctos_dut_type=VLOG;
        m_ctos_ref_type=UNKNOWN;
        m_dut_vlog=new dflipflop_ctos_wrapper_vlog("m_dut_vlog", "");
        din_vlog=new sc_signal<sc_lv<1> > ("din_vlog");
        m_dut_vlog->din(*din_vlog);
        m_dut_vlog->clk(clk);
        m_dut_vlog->reset(reset);
        dout_vlog_dut=new sc_signal<sc_lv<1> > ("dout_vlog_dut");
        m_dut_vlog->dout(*dout_vlog_dut);
        std::cout << "CtoS Verification Wrapper: Instantiating RTL module " << m_dut_vlog->hdl_name() << " as DUT" << std::endl;
        SC_METHOD(ctos_convert_input);
        sensitive << din;
        SC_METHOD(ctos_convert_output);
        dont_initialize();
        sensitive << *dout_vlog_dut;
    }
};




    typedef dflipflop_ctos_wrapper dflipflop_ctos;
  #define DFLIPFLOP_CTOS_INSTANCE(INSTNAME) dflipflop_ctos(INSTNAME, CTOS_TARGET_SUFFIX(CTOS_MODEL), NULL, false)
  #define DFLIPFLOP_CTOS_COMPARE_INSTANCE(INSTNAME, REFNAME) dflipflop_ctos(INSTNAME, CTOS_TARGET_SUFFIX(CTOS_MODEL), REFNAME, true)
  #define DFLIPFLOP_CTOS_RTL_ONLY_INSTANCE(INSTNAME) dflipflop_ctos(INSTNAME, dflipflop_ctos::SimulateRTLOnly)
#endif // ifdef dflipflop_ctos_wrapper_P

