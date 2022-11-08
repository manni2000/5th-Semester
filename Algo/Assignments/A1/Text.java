class Text
 {
    public static void main(String[] args) {
        long start=System.nanoTime();
        System.out.println("Value="+(power(2,64)));
        long end=System.nanoTime();
        System.out.println();
        System.out.println("Time taken="+ (end-start)/1000+ " micro seconds");
    }
    public static double power(int x,int n)
    {
        
          if(n==1)
            return x;
            else
          return (power(x,n/2)*power(x,n/2));
    }
}
