//http://www.reddit.com/r/dailyprogrammer/comments/2snhei/20150116_challenge_197_hard_crazy_professor/

#include<iostream>
#include<memory>

int main()
{
	const std::size_t num_baseprimes=8;
	const std::uint64_t baseprimes[8]={2,3,5,7,11,13,17,19};
	const std::size_t target=1000000;

	std::size_t total_numbers;
	size_t num_iterations;
	for(	total_numbers=1,num_iterations=0;
		total_numbers < target;
		total_numbers*=8,num_iterations++);	//82097152; //8^(ceil(log_8(target))


	std::unique_ptr<std::uint64_t[]> numbers(new std::uint64_t[total_numbers]);
	std::size_t cstart=1;
	std::uint64_t* data=&numbers[0];
	for(std::size_t i=0;i<num_iterations;i++)
	{
		cstart*=8;
		for(std::size_t n=0;n<num_baseprimes;n++)
		{
			uint64_t bp=baseprimes[n];
			std::transform(
				data,data+cstart,
				data+cstart,
				[bp](uint64_t n_in) { return n_in*bp; }
			);
		}
	}
	std::nth_element(data,data+target,data+total_numbers);
	cout << data[target] << endl;
	return 0;
}
