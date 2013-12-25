size_t strchrncount(char * haystack, char needle, size_t max)
{
	size_t i=0;
	size_t count=0;

	if(!haystack)
		return 0;

	while(*haystack && count<max)
	{
		if(*haystack==needle)
			i++;

		haystack++;
		count++;
	}

	return i;
}

unsigned char strendswith(char * haystack, char * needle)
{
	if(!haystack || !(*haystack) || !needle || !(*needle))
		return 0;

	if(strlen(needle)>strlen(haystack))
		return 0;

	if(!strcmp(haystack+(strlen(haystack)-strlen(needle)), needle))
		return 1;

	return 0;
}

char * strstrstrip(char * haystack, char * needle)
{
	char * loc=0;
	size_t haystack_size=strlen(haystack);
	size_t needle_size=strlen(needle);

	while((loc=strstr(haystack, needle))!=NULL)
	{
		haystack_size -= needle_size;
		memmove(loc, loc+needle_size, haystack_size);
	}

	return haystack;
}