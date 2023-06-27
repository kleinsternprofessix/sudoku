// #include <iostream>
// #include <cctype>
// #include <random>

// int main( void )
// {
//   std::random_device os_seed;
//   const uint_least32_t seed = os_seed();
  
//   std::mt19937 generator( seed );
//   std::uniform_int_distribution< uint_least32_t > distribute( 0, 90 );

//   for( int i = 0; i < 12; ++i )
//     std::cout << distribute( generator ) << std::endl;
//   return 0;
// }