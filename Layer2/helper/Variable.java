package helper;
import java.util.*;

public class Variable
{
  public String name;
  public String type;
  public int pointer_level;
  public int array_level;
  public ArrayList<String> dimexpr;
  public String rhs;
  // String code;

  public Variable(String name, String type, int pointer_level, int array_level, ArrayList<String> dimexpr)
  {
    this.name = name;
    this.type = type;
    this.pointer_level = pointer_level;
    this.array_level = array_level;
    this.dimexpr = dimexpr;
  }

  public Variable(String name, String type, int pointer_level, int array_level, ArrayList<String> dimexpr, String rhs)
  {
    this.name = name;
    this.type = type;
    this.pointer_level = pointer_level;
    this.array_level = array_level;
    this.rhs = rhs;
    this.dimexpr = dimexpr;
  }

}