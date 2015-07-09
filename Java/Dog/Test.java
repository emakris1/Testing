public class Test
{
    public static void foo(Dog someDog)
    {
        System.out.println("someDog starts as a " + someDog.breed);

        someDog.breed = "Yorkshire Terrier";
        System.out.println("We change someDog's breed to a " + someDog.breed);

        someDog = new Dog("Labrador Retriever");
        System.out.println("We assign someDog to a completely new Dog whose breed is " + someDog.breed);

        someDog.breed = "Siberian Husky";
        System.out.println("Finally, we change someDog's breed again to a " + someDog.breed);
    }

    public static void main(String[] args)
    {
        Dog myDog = new Dog("Border Collie"); // This is not a Dog, this is a POINTER to a Dog
        System.out.println("myDog starts as a " + myDog.breed);
        System.out.println("We pass myDog over to foo as someDog");
        System.out.println();
        Test.foo(myDog);
        System.out.println();
        System.out.println("But, myDog is STILL a " + myDog.breed + ", which is the first breed change we made before assigning someDog to a new Dog!");
    }
}
