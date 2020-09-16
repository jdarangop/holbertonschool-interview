#!/usr/bin/python3
""" Count it """
import requests


def count_words(subreddit, word_list, titles=[], after="null"):
    """ returns the amount of times the words are
        in the titles of a subreddit.
        Args:
            subreddit: (str) subreddit to search.
            word_list: (list) words to search.
            titles: (list) titles of the subreddit.
        Returns:
            None.
    """
    header = {'User-Agent': 'linux:1:v1.0 (by /u/jdarangop)'}
    params = {"limit": "100", "after": after}
    response = requests.get('https://www.reddit.com/r/' +
                            subreddit + '/hot.json',
                            headers=header,
                            params=params,
                            allow_redirects=False)
    if response.status_code != 200:
        return None
    data = response.json().get('data')
    dicts = response.json().get('data').get('children')
    for i in dicts:
        titles.append(i.get('data').get('title'))
    after = response.json().get('data').get('after')

    if after is None:
        counter_dict = {j: 0 for j in word_list}
        for word in word_list:
            counter = 0
            for title in titles:
                title_words = title.split()
                lower = [j.lower() for j in title_words]
                counter += lower.count(word.lower())
            counter_dict[word] += counter
        sorted_dict = sorted(counter_dict.items(),
                             key=lambda x: x[1], reverse=True)
        for i, j in sorted_dict:
            if j != 0:
                print("{}: {}".format(i, j))
    else:
        return count_words(subreddit, word_list, titles, after)
