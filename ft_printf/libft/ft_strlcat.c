#include "libft.h"

// man strlcat
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (size + src_len);
	dest += dest_len;
	size -= dest_len;
	while (*src && --size)
		*(dest++) = *(src++);
	*dest = '\0';
	return (src_len + dest_len);
}
