package org.quickfix.field; 
import org.quickfix.DoubleField; 
import java.util.Date; 

public class MktOfferPx extends DoubleField 
{ 

  public MktOfferPx() 
  { 
    super(646);
  } 
  public MktOfferPx(double data) 
  { 
    super(646, data);
  } 
} 
