package org.quickfix.field; 
import org.quickfix.StringField; 
import java.util.Date; 

public class UnderlyingMaturityDate extends StringField 
{ 

  public UnderlyingMaturityDate() 
  { 
    super(542);
  } 
  public UnderlyingMaturityDate(String data) 
  { 
    super(542, data);
  } 
} 
