import syntaxtree.*;
import visitor.*;

public class ParserMain {
   public static void main(String [] args) {
      try {
         Node root = new CParser(System.in).Goal();
         System.out.println("Program parsed successfully");
         // root.accept(new GJDepthFirst<Integer,String>(),null); // Your assignment part is invoked here.
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


