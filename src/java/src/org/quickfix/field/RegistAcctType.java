package org.quickfix.field; 
import org.quickfix.StringField; 
import java.util.Date; 

public class RegistAcctType extends StringField 
{ 

  public RegistAcctType() 
  { 
    super(493);
  } 
  public RegistAcctType(String data) 
  { 
    super(493, data);
  } 
} 
