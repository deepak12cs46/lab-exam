select fb_post.id,fb_post.text
from fb_post,fb_author,fb_comment
where fb_post.id=fb_comment.post and fb_post.author=fb_comment.author and fb_author.name like '%SAI%' 


fp as 
(
select fb_comment.id as comm,fb_author.id as author,row_number() over (partition by fb_author.id order by fb_comment.cdate) as rownumb
from fb_author,fb_comment
where fb_comment.author=fb_author.id
)

fp.author=lp.author and fp.author=fc.author and fc.author=lc.author and 
