package helper;
import java.util.*;

public class GlobalSymTab
{
  public HashMap<String, FuncSymTab> functions = new HashMap<String, FuncSymTab>();
  public FuncSymTab curr_func;

  public ArrayList<String> structs_declared = new ArrayList<String>();
  public ArrayList<String> enums_declared = new ArrayList<String>(); 

  public void add_function(String name)
  {
    FuncSymTab x = new FuncSymTab(name);
    functions.put(name, x);
    this.curr_func = x;
  }

  public FuncSymTab get_function(String name)
  {
    return functions.get(name);
  }

  public void add_struct(String name, String code)
  {
    // System.out.println("CALLED " + name);
    if(curr_func!=null)
    {
      // curr_func.structs_declared.put(name, code);
      curr_func.structs_declared.add(code);
    }
    else
    {
      // structs_declared.put(name, code);
      structs_declared.add(code);
    }
  }

  public void add_enum(String name, String code)
  {
    if(curr_func!=null)
    {
      curr_func.enums_declared.add(code);
    }
    else
    {
      enums_declared.add(code);
    }
  }

}
