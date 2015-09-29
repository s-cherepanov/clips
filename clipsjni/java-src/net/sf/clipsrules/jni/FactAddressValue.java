package net.sf.clipsrules.jni;

public class FactAddressValue extends PrimitiveValue
  {
   private Environment owner;
   private Long value;

   /*********************/
   /* FactAddressValue: */
   /*********************/
   public FactAddressValue(
     long value,
     Environment env)
     {
      this.value = value;
      owner = env;
     }

   /*************/
   /* getValue: */
   /*************/
   @Override
   public Long getValue()
     {
      return this.value;
     }

   @Override
   public CLIPSType getCLIPSType()
     { return CLIPSType.FACT_ADDRESS; }

   /*******************/
   /* getEnvironment: */
   /*******************/
   public Environment getEnvironment()
     { return owner; }
     
   /*******************/
   /* getFactAddress: */
   /*******************/     
   public long getFactAddress()
     { return getValue().longValue(); }

   /****************/
   /* getFactSlot: */
   /****************/     
   public PrimitiveValue getFactSlot(
     String slotName) throws Exception
     { return Environment.getFactSlot(this,slotName); }

   /*****************/
   /* getFactIndex: */
   /*****************/     
   public long getFactIndex()
     { return Environment.factIndex(this); }

   /***********/
   /* retain: */
   /***********/
   @Override
   public void retain()
     {
      owner.incrementFactCount(this);
     }

   /************/
   /* release: */
   /************/
   @Override
   public void release()
     {
      owner.decrementFactCount(this);
     }
     
   /*************/
   /* toString: */
   /*************/
   @Override
   public String toString()
     {        
      return "<Fact-" + getFactIndex() + ">";
     }

   @Override
   public boolean isFactAddress()
     { return true; }
  }
