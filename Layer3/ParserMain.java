import syntaxtree.*;
import visitor.*;

public class ParserMain {
   public static void main(String [] args) {
      try {
         Node root = new CParser(System.in).Goal();
         // System.out.println("Program parsed successfully");
         // root.accept(new GJDepthFirst<Integer,String>(),null); // Your assignment part is invoked here.
         GJDepthFirst<String, Integer> temp = new GJDepthFirst<String,Integer>();
         root.accept(temp, 0);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


