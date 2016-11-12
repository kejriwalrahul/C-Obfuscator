package helper;
import java.util.*;

public class FuncSymTab
{
  public String name;
  public HashMap<String, Variable> variables = new HashMap<String, Variable>();
  public ArrayList<String> decl_order = new ArrayList<String>();

  public ArrayList<String> structs_declared = new ArrayList<String>();
  public ArrayList<String> enums_declared = new ArrayList<String>();

  public FuncSymTab(String name)
  {
    this.name = name;
  }

  public void put_variable(String name, String type, int pointer_level, int array_level, ArrayList<String> dimexpr, String rhs)
  {
    Variable v;
    if(rhs!=null)
      v = new Variable(name, type, pointer_level, array_level, dimexpr, rhs);
    else
      v = new Variable(name, type, pointer_level, array_level, dimexpr);

    this.variables.put(name, v);
    this.decl_order.add(name);
  }

  public Variable get_variable(String name)
  {
    return this.variables.get(name);
  }

}