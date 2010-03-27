README -- Browsing History Recommender

This module adds two blocks:
1) Users who browsed this node also browsed
2) Recommended for you

To make the recommendations, the module uses the {history} table that keeps
track of 30 days of node browsing history. Also, you can select the "boost
comments" option to use the commenting history as input.

This module requires Recommender API at http://drupal.org/project/recommender.

After configure/setup, please go to admin/settings/recommender to generate the
recommendations.


*** Future features ***
1) Take "accesslog" as browsing history input.
2) Take Google Analytics as browsing history input.